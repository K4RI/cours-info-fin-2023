package td;
import com.rabbitmq.client.Channel;
import com.rabbitmq.client.ConnectionFactory;

import java.nio.charset.StandardCharsets;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.Time;

/**
 * 1 - Capteur.
 * Capte la température, et l'envoie au régulateur.
 */
public class Sensor {

    private final static String QUEUE_NAME = "hello";
    static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/smartRoom";
    static final String USER = "root";
    static final String PASS = "azerty";

    static final int pas = 1000; // nombre de millisecondes avant chaque màj

    public static void main(String[] argv) throws Exception {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");

        java.sql.Connection conn = null;
        Statement stmt = null;
        Class.forName(JDBC_DRIVER);
        System.out.println("Connexion a la base de donnees...");
        conn = DriverManager.getConnection(DB_URL, USER, PASS);

        try (com.rabbitmq.client.Connection connection = factory.newConnection();
            Channel channel = connection.createChannel()) {
            channel.queueDeclare(QUEUE_NAME, false, false, false, null);
            
            int temperature = 20;

            //for (int i=0; i < 1000; i++) {
            while(true){
                // la température évolue
                temperature += Math.floor(Math.random()*3 - 1);

                // on l'envoie dans la queue, pour le régulateur
                channel.basicPublish("", QUEUE_NAME, null, String.valueOf(temperature).getBytes(StandardCharsets.UTF_8));
                System.out.println(" [x] Sent '" + temperature + "'");

                // JDBC : stockage de la température et du datetime dans la base de données
                long now = System.currentTimeMillis();
                Time sqlTime = new Time(now);
                Date sqlDate = new Date(now);
                String sql = "INSERT INTO temperatures "
                    + "VALUES ('" + temperature + "', '" + sqlDate + "', '" + sqlTime + "')";
                stmt = conn.createStatement();
                stmt.executeUpdate(sql);
                Thread.sleep(pas);
            }
        }
    }
}
