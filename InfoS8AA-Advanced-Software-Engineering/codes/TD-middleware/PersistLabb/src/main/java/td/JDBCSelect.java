/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package td;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author charoy
 */
public class JDBCSelect {

    static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/Pompiers"; // il faut créer cette base de donnée

    //  Database credentials
    static final String USER = "root";
    static final String PASS = "azerty";

    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        Connection conn = null;
        Statement stmt = null;

        //STEP 2: Register JDBC driver
        Class.forName(JDBC_DRIVER);

        //STEP 3: Open a connection
        System.out.println("Connecting to database...");
        conn = DriverManager.getConnection(DB_URL, USER, PASS);

        //STEP 4: Execute a query
        System.out.println("Creating statement...");

        String sql = "SELECT * FROM Personnel";
        stmt = conn.createStatement();
        ResultSet rs=stmt.executeQuery(sql);
        while (rs.next()) {
            String id=rs.getString("Matricule");
            String nom=rs.getString("Nom");
            String prenom =rs.getString("Prénom");
            System.out.println(" Item "+id+" = "+ nom + " " + prenom);
        }
        conn.close();

        System.out.println("Goodbye!");
    }    
}
