/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package td;

import java.rmi.RemoteException;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

/**
 *
 * @author charoy
 */
public class StoreServant implements IStore {
    EntityManagerFactory emf;
    EntityManager em;
    public StoreServant() {
        emf = Persistence.createEntityManagerFactory("MyPU");
        em = emf.createEntityManager();

    }
    @Override
    public long store(String data) throws RemoteException {
        MyEntity e=new MyEntity();
        e.setMyValue(data);
        em.getTransaction().begin();
        em.persist(e);
        em.getTransaction().commit();
        return e.getId();
    }

    @Override
    public String retrieve(long id) throws RemoteException {
        MyEntity e=em.find(MyEntity.class, id);
        return e.getMyValue();
    }
    
}
