import java.io.FileInputStream;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;

class Logging {
    public static <T extends Comparable<T>> int countGreaterThan(T[] tab, T elem) {
        int count = 0;
        for (T val : tab) {
            if (val.compareTo(elem) > 0) {
                ++count;
            }
        }
        return count;
    }
    private static final LogManager logManager = LogManager.getLogManager();
    private static final Logger LOGGER = Logger.getLogger(Logging.class.getPackage().getName() );

    static {
        try {
            logManager.readConfiguration( new FileInputStream("logging.properties") );
        } catch( Exception exception ) {
            LOGGER.log( Level.SEVERE, "Cannot read configuration file", exception );
        }
    }

    public static void main(String[] args) {
        LOGGER.info( "Hello World with java.util.logging" );

        Integer[] liste = {10, 20, 30, -40, 50};
        LOGGER.log( Level.INFO, "value == {3}", liste );
        liste[3] = 40;
        LOGGER.log( Level.INFO, "value == {3}", liste );
        LOGGER.info("cpt = " + countGreaterThan(liste, 25) );
    }
}

