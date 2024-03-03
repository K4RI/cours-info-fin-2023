package td;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.CallableStatement;

import java.sql.ResultSet;
import java.sql.ResultSetMetaData;

// https://dev.mysql.com/doc/connector-j/en/connector-j-examples.html

// Notice, do not import com.mysql.cj.jdbc.*
// or you will have problems!

public class ExampleLoadDriver {

    private static final int choix = 2;

    public static void main(String[] args) {
        try {
            // The newInstance() call is a work around for some broken Java implementations

            Class.forName("com.mysql.cj.jdbc.Driver").getDeclaredConstructor().newInstance();
        } catch (Exception ex) {
            // handle the error
        }

        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        
        try {
            conn =
            DriverManager.getConnection("jdbc:mysql://localhost:3306/Pompiers?" +
                                        "user=root&password=azerty");
          
            // Do something with the Connection
            switch (choix) {
                case 1:
                    stmt = conn.createStatement();
                    rs = stmt.executeQuery("SELECT * FROM Personnel WHERE AdrVille = 'Laxou';");
                    break;
            
                case 2:
                    // or alternatively, if you don't know ahead of time that the query will be a SELECT...
                    stmt = conn.createStatement();
                    if (stmt.execute("SELECT * FROM Personnel WHERE AdrVille = 'Laxou';")) {
                        rs = stmt.getResultSet();
                    }
                    break;
            
                case 3:
                    // ou appel d'une procédure du serveur phpmyadmin
                    // https://www.tutorialspoint.com/java_mysql/java_mysql_callable_statement.htm
                    CallableStatement cstmt = conn.prepareCall("{call demoSp(?)}");
                    cstmt.setString(1, "Laxou"); // le 1er paramètre
                    cstmt.execute();
                    cstmt.setString(1, "abcdefg");
                    rs = cstmt.getResultSet();
                    break;
                
                default:
                    throw new IllegalArgumentException("variable 'choix' entre 1 2 et 3 svp");
            }         
            
            // Now do something with the ResultSet ....
            ResultSetMetaData rsmd = rs.getMetaData();
            while (rs.next()) {
                for (int i = 1; i <= rsmd.getColumnCount(); i++) {
                    System.out.print(rsmd.getColumnName(i) + " : " + rs.getString(i) + "\n");
                }
                System.out.print("\n\n");
            }       

        } catch (SQLException ex) {
            // handle any errors
            System.out.println("SQLException: " + ex.getMessage());
            System.out.println("SQLState: " + ex.getSQLState());
            System.out.println("VendorError: " + ex.getErrorCode());
        }
        
        finally {
            // it is a good idea to release
            // resources in a finally{} block
            // in reverse-order of their creation
            // if they are no-longer needed

            if (rs != null) {
                try {
                    rs.close();
                } catch (SQLException sqlEx) { } // ignore

                rs = null;
            }

            if (stmt != null) {
                try {
                    stmt.close();
                } catch (SQLException sqlEx) { } // ignore

                stmt = null;
            }
        }
    }
}