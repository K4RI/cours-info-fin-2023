/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package td;

import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

/**
 *
 * @author charoy
 */
public class StoreServer {
    public static void main(String[] args) throws RemoteException, AlreadyBoundException {
        // Localisation du serveur de nommage
        Registry r=LocateRegistry.createRegistry(1099);
        
        IStore s=new StoreServant();
        IStore stub= (IStore) UnicastRemoteObject.exportObject(s, 0);
        
        r.bind("store",s);
    }
        
}
