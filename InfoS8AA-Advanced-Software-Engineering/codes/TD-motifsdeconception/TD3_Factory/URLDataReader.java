import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;

public class URLDataReader extends DataReader {

	public URLDataReader(String chemin) {
		try
		{
			URL url = new URL(chemin);
			in = new BufferedReader(new InputStreamReader(url.openStream()));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
