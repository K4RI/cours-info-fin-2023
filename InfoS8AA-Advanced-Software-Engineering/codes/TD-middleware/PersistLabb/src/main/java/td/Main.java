/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package td;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
/**
 *
 * @author charoy
 */
public class Main {

    /**
     * @param args the command line arguments
     * 
     * Creating and storing an object
     * 
     */
    public static void main(String[] args) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("MyPU");
        EntityManager em = emf.createEntityManager();
        
        MyEntity me=new MyEntity();
        me.setMyValue("test");
        
        em.getTransaction().begin();
        em.persist(me);
        em.getTransaction().commit();
        
        em.close();
    }

}
