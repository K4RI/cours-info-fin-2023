import java.io.IOException;
import java.io.Reader;

public class DataReader {
	protected Reader in = null;

	public String read(int bytes) throws IOException {
		if (in == null || bytes <= 0) throw new IOException("impossible de lire le flux");
		char[] c = new char[bytes];
		int read = in.read(c);
		return (read == -1 ? null : new String (c,0,read));
	}
}
