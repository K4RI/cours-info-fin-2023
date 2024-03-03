/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package td;

import java.util.Iterator;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.Query;

/**
 *
 * @author charoy
 */
public class StoreRetrieve {
    public static void main(String[] args) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("MyPU");
        EntityManager em = emf.createEntityManager();
        
        MyEntity me=new MyEntity();
        me.setMyValue("test");
        MyEntity me2=new MyEntity();
        me2.setMyValue("test1");
        MyEntity me3=new MyEntity();
        me3.setMyValue("test2");
        
        em.getTransaction().begin();
        em.persist(me);
        em.persist(me2);
        em.persist(me3);
        em.getTransaction().commit();
        
        Query q=em.createQuery("Select m from MyEntity m", MyEntity.class);
        List<MyEntity> s=q.getResultList();
        for (MyEntity l : s) {
            System.out.println(" item "+l.getId()+" = "+l.getMyValue());
        }
        em.close();
        
    }
    
}
