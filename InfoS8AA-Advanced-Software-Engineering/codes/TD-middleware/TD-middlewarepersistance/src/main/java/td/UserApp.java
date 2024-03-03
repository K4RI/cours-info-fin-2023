package td;
import java.io.IOException;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.Time;
import java.util.UUID;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

import com.rabbitmq.client.*;

/**
 * 3 - Application mobile.
 * Reçoit les annonces du régulateur.
 */
public class UserApp {
    private static final String EXCHANGE_NAME = "topic_logs";
    private static final String RPC_QUEUE_NAME = "rpc_queue";

    static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/smartRoom";
    static final String USER = "root";
    static final String PASS = "azerty";

    private static final int temperatureSeuil = 30;

    public static void main(String[] argv) throws Exception {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        com.rabbitmq.client.Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        // on envoie une température désirée
        try {
            int newTemperatureDesiree = (int) Math.floor(Math.random()*10 + 15);
            System.out.println(" [x] On demande la nouvelle temperature a " + newTemperatureDesiree);
            String response = call(channel, String.valueOf(newTemperatureDesiree));
            System.out.println(" [.] Recu : '" + response + "'");
        } catch (IOException | InterruptedException | ExecutionException e) {e.printStackTrace();}

        // on demande si on a déjà dépassé une valeur
        System.out.println("Connexion a la base de donnees...");
        Class.forName(JDBC_DRIVER);
        java.sql.Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
        System.out.println("Envoi de la requete...");
        String sql = "SELECT * FROM temperatures WHERE temperature = " + temperatureSeuil;
        Statement stmt = conn.createStatement();
        ResultSet rs=stmt.executeQuery(sql);
        Date date;
        Time time;
        if (rs.next() == false) {
            System.out.println("Temperature de " + temperatureSeuil + " jamais atteinte");
          } else {
            date = rs.getDate("date_captation");
            time = rs.getTime("heure_captation");
            System.out.println("Temperature " + temperatureSeuil + " atteinte le " + date + " a " + time);
        }
        
        rs=stmt.executeQuery("SELECT * FROM temperatures WHERE temperature = (SELECT MAX(temperature) FROM temperatures)");
        if (rs.next() == false) {
            System.out.println("Base de donnees vide");
        } else {
            int t = rs.getInt("temperature");
            date = rs.getDate("date_captation");
            time = rs.getTime("heure_captation");
            System.out.println("Temperature MAX : " + t + " (atteinte le " + date + " a " + time + ")");

            rs=stmt.executeQuery("SELECT * FROM temperatures WHERE temperature = (SELECT MIN(temperature) FROM temperatures)");
            rs.next();
            t = rs.getInt("temperature");
            date = rs.getDate("date_captation");
            time = rs.getTime("heure_captation");
            System.out.println("Temperature MIN : " + t + " (atteinte le " + date + " a " + time + ")");
        }


        // on s'abonne au topic, càd filtrer les annonces
        channel.exchangeDeclare(EXCHANGE_NAME, BuiltinExchangeType.TOPIC);
        String queueName = channel.queueDeclare().getQueue();
        // par exemple que les action high, ou les actions de chauffage, ou les deux ?
        channel.queueBind(queueName, EXCHANGE_NAME, "*.HIGH");
        channel.queueBind(queueName, EXCHANGE_NAME, "HEAT.*");
        System.out.println(" [*] Waiting for messages. To exit press CTRL+C");
        DeliverCallback deliverCallback = (consumerTag, delivery) -> {
            // et on reçoit les notifs
            String message = new String(delivery.getBody(), "UTF-8");
            System.out.println(" [x] Received '" + delivery.getEnvelope().getRoutingKey() + "':'" + message + "'");
        };
        channel.basicConsume(queueName, true, deliverCallback, consumerTag -> { });
    }

    public static String call(Channel channel, String message) throws IOException, InterruptedException, ExecutionException{
        final String corrId = UUID.randomUUID().toString();

        String replyQueueName = channel.queueDeclare().getQueue();
        AMQP.BasicProperties props = new AMQP.BasicProperties
                .Builder()
                .correlationId(corrId)
                .replyTo(replyQueueName)
                .build();

        channel.basicPublish("", RPC_QUEUE_NAME, props, message.getBytes("UTF-8"));

        final CompletableFuture<String> response = new CompletableFuture<>();
        
        String ctag = channel.basicConsume(replyQueueName, true, (consumerTag, delivery) -> {
            if (delivery.getProperties().getCorrelationId().equals(corrId)) {
                response.complete(new String(delivery.getBody(), "UTF-8"));
            }
        }, consumerTag -> {
        });
        String result = response.get();
        channel.basicCancel(ctag);
        return result;
    }
}

