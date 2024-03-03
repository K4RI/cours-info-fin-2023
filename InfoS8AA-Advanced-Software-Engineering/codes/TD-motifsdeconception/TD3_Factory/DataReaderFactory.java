import java.io.IOException;

public class DataReaderFactory {

    static DataReader getReader(String s){
        if ((s.substring(0, 4)).equals("http")){
            return new URLDataReader(s);
        } else {
            return new FileDataReader(s);
        }
    }
    public static void main(String[] args) throws IOException {
        String chemin = null;
        // chemin = "TD-MiniTD/ENSMN_2A_MOSI_TP_Design_PatternsNouveau.txt";
        // chemin = "TD-MiniTD/DataReaderFactory.java";
        chemin = "https://pastebin.com/raw/hH6VX2M4";
        // chemin = "https://cdn.discordapp.com/attachments/537744173323780106/1164473614737870860/notes.txt";
        DataReader r = DataReaderFactory.getReader(chemin);
        System.out.println("Read: "+r.read(512));
    }
}
