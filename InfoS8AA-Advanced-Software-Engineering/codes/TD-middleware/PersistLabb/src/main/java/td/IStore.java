/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package td;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author charoy
 */
public interface IStore extends Remote {
    public long store(String data) throws RemoteException;
    public String retrieve(long id) throws RemoteException;
}
