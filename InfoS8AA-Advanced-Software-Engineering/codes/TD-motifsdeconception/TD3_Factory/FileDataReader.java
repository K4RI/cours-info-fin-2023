import java.io.FileReader;

public class FileDataReader extends DataReader {

	public FileDataReader(String chemin) {
		try
		{
			in = new FileReader(chemin);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
