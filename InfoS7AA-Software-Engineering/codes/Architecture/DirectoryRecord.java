package fatfs;

import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;

/** The DirectoryRecord class encapsulates a ByteBuffer of 32 bytes representing a directory record.
 *
 * - octets 0-7 contiennent les 8 lettres du nom du fichier (si le premier caractère est 0x00, l'enregistrement est libre);
 * - octets 8-10 contienent les 3 lettres de l'extension du fichier;
 * - octet 11 contient les bits d'attributs du fichier  (le bit 0x08 = répertoire)
 * - octets 20-23 contiennent l'entier correspondant à l'indice du premier bloc du fichier (normalement, les différents octets représentant cette valeur ne sont pas contigus en mémoire, nous les regroupons pour simplifier l'implémentation);
 * - octets 28-31 contiennent l'entier correspondant à la taille du fichier en octets.
 *
 */
public class DirectoryRecord 
{
    private ByteBuffer content;
    final static int recordSize = 32;

    DirectoryRecord(ByteBuffer record);

    /** Create a new directory record, assume parameters are properly formated to the 8.3 filename
     * format with trailing spaces
     *
     * @param path_element name and extension of the file
     * @param first_cluster index of first cluster of the new file
     * @param is_directory whether the file is a directory
     * @return a directory record representing the file
     */
    static DirectoryRecord createNewRecord(PathElement path_element,
                                           int first_cluster, boolean is_directory);

    /** Check if the record is empty
     *
     * @return true if the record is empty
     */
    public boolean isEmpty();

    /** Mark the record as empty
     */
    public void markAsDeleted();

    /**
     * TODO check paramter type, if possible avoid copy in implementation !!!
     * @param path_element
     * @return
     */
    public boolean isFile(PathElement path_element);

    public ByteBuffer getName();

    public void setName(byte[] name);

    public ByteBuffer getExtension();

    public void setExtension(byte[] ext);

    public int getFirstCluster();

    public void setFirstCluster(int l);

    public int getLength();

    public void setLength(int l);

    public boolean isDirectory();

    public void setDirectory(boolean isDir);

    /** Access to ByteBuffer representing the record
     */
    public ByteBuffer getContent() {
        return this.content;
    }

    /** Returns a string describing the file
     */
    public String toString() {
            return StandardCharsets.UTF_8.decode(this.getName()).toString()
                    + StandardCharsets.UTF_8.decode(this.getExtension()).toString()
                    + " " + this.getLength();
    }

}
