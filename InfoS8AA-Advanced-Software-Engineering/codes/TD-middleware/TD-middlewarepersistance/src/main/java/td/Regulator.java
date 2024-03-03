package td;
import com.rabbitmq.client.AMQP;
import com.rabbitmq.client.BuiltinExchangeType;
import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.DeliverCallback;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;


/**
 * 2 - Régulateur.
 * Reçoit la température du capteur, agit, et annonce ses actions.
 */
public class Regulator {

    private final static String QUEUE_NAME = "hello";
    private static final String EXCHANGE_NAME = "topic_logs";
    private static final String RPC_QUEUE_NAME = "rpc_queue";

    static int temperatureDesiree = 20;

    public enum TypeAction {HEAT, COOL};
    public enum Intensite {LOW, HIGH};

    static Channel channel;
    static EntityManager em;


    private static void action(TypeAction t, Intensite i) throws UnsupportedEncodingException, IOException{
        String message = "";
        message += (t == TypeAction.HEAT) ? "CHAUFFER " : "REFROIDIR ";
        message += (i == Intensite.LOW) ? "FAIBLE" : "FORT";
        // on envoie dans un topic correspondant, pour l'application
        channel.basicPublish(EXCHANGE_NAME, t + "." + i, null, message.getBytes("UTF-8"));
        System.out.println(message);

        Action a = new Action();
        a.setType((t == TypeAction.HEAT) ? 1 : 2);
        a.setStrength((i == Intensite.LOW) ? 1 : 2);
        em.getTransaction().begin();
        em.persist(a);
        em.getTransaction().commit();
    }

    public static void main(String[] argv) throws Exception {
        // init JDBC
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        Connection connection = factory.newConnection();
        channel = connection.createChannel();

        channel.queueDeclare(QUEUE_NAME, false, false, false, null);
        channel.exchangeDeclare(EXCHANGE_NAME, BuiltinExchangeType.TOPIC);

        channel.queueDeclare(RPC_QUEUE_NAME, false, false, false, null);
        channel.queuePurge(RPC_QUEUE_NAME);
        channel.basicQos(1);        

        // init JPA
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("smartRoom");
        em = emf.createEntityManager();
        
        System.out.println(" [*] Waiting for messages. To exit press CTRL+C");
        System.out.println(" [x] Awaiting RPC requests");

        DeliverCallback deliverCallback = (consumerTag, delivery) -> {
            if (delivery.getEnvelope().getRoutingKey().equals("hello")){ // 
                // réception du message du capteur
                int temperature = Integer.parseInt(new String(delivery.getBody(), StandardCharsets.UTF_8));
                System.out.println(" [x] Received '" + temperature + "'");
                // on détermine l'action : réchauffer/refroidir, faiblement/fortement
                TypeAction t = (temperature > temperatureDesiree) ? TypeAction.COOL : TypeAction.HEAT;
                Intensite i = (Math.abs(temperature - temperatureDesiree) >= 5) ? Intensite.HIGH : Intensite.LOW;
                action(t, i);
            }
            else if (delivery.getEnvelope().getRoutingKey().equals("rpc_queue"))
            {
                // réception du RPC de l'utilisateur
                AMQP.BasicProperties replyProps = new AMQP.BasicProperties
                        .Builder()
                        .correlationId(delivery.getProperties().getCorrelationId())
                        .build();
                String response = "";
                try {
                    int newTemperatureDesiree = Integer.parseInt(new String(delivery.getBody(), "UTF-8"));
                    if (Math.abs(temperatureDesiree - newTemperatureDesiree) <= 3){
                        response = "oui";
                        System.out.println(" [.] Temperature desiree " + temperatureDesiree + " modifiee a : " + temperatureDesiree);
                        temperatureDesiree = newTemperatureDesiree;
                    } else {
                        response = "non";
                        System.out.println(" [.] Temperature desiree non-modifiee");
                    }
                } catch (RuntimeException e) {
                    System.out.println(" [.] " + e);
                } finally {
                    channel.basicPublish("", delivery.getProperties().getReplyTo(), replyProps, response.getBytes("UTF-8"));
                    channel.basicAck(delivery.getEnvelope().getDeliveryTag(), false);
                }
            }
        };

        channel.basicConsume(QUEUE_NAME, true, deliverCallback, consumerTag -> { });        
        channel.basicConsume(RPC_QUEUE_NAME, false, deliverCallback, (consumerTag -> {}));        
    }
}
