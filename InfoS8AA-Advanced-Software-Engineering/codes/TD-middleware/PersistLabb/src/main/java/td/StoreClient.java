/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package td;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author charoy
 */
public class StoreClient {
    public static void main(String[] args) throws RemoteException, NotBoundException {
    	System.setProperty("java.rmi.server.hostname","192.168.1.2");
        Registry r=LocateRegistry.getRegistry();
        IStore s=(IStore) r.lookup("store");
        long key1=s.store("tagada");
        long key2=s.store("tsoin");
        System.out.println(key1+" = "+s.retrieve(key1));
    }    
    
}
