package fatfs;

import fs.IDevice;

import java.nio.ByteBuffer;
import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.OptionalInt;

class FATAccess {

    private static boolean endOfLink(int status) {
        return status < 0x02 || status >= 0xFFFFFF7;
    }

    FATAccess(IDevice dev, int address_FAT0,
              int nb_FAT_sector, int nb_FAT);

    /** Get the address of the FAT0 in sector */
    int getAddressFAT0();

    /** Get the number of fat */ 
    int getNbFATSector();

    /** Get the number of fat entry per sector
     */
    private int fatEntryPerSector();

    /** Mark all clusters as free
     */
    public void freeFAT();

    /** Allocate a new cluster (mark it as end of file in allocation table)
     *
     *  @return cluster id if found
     */
    public OptionalInt getEmptyCluster();
    // optional => can be created with OptionalInt.of(value) or OptionalInt.empty();
    // can be tested with opt.isEmpty() and used with opt.getAsInt()

    /** Update the status of a given sector
     *
     * @param cluster_id index of the cluster to be updated
     * @param status new status (0x0FFFFFFF : last sector, 0x00 : empty, other : id of next sector)
     */
    public void setClusterStatus(int cluster_id, int status);

    /** Return the status registered in FAT for the given cluster
     *
     * @param cluster_id index of cluster
     * @return status of cluster
     */
    public int getClusterStatus(int cluster_id);

    /** Add a new cluster to a file
     *
     * @param prev_cluster_id index of the last cluster of the file
     *
     * @return return the id of the added sector
     *
     * @todo should throw an exception "out of memory"
     */
    int addClusterToFile(int prev_cluster_id);

    /** Get the amount of free space
     *
     * @return the amount of free space in the currently mounted device, 0 if no device is mounted
     */
    public int totalFreeSpace();


    /** Generate a cluster iterator (cf ClusterIterator class)
      * @param cluster_id id of first cluster of the file
      * @param allocate_cluster whether a new cluster should be allocated when the end of file is reached 
      */
    FATAccess.ClusterIterator getClusterIterator(int cluster_id, boolean allocate_cluster);

    /** A ClusterIterator allows iterating over FAT entry that belong to a linked-list of
     * clusters. Also provide the capability to allocate new cluster on demand.
     */
    class ClusterIterator
    {
        /**
         * @param cluster first cluster of the linked-list
         * @param allocate_cluster whether a new cluster should be allocated when the end of file
         *                         is reached
         */
        ClusterIterator(int cluster, boolean allocate_cluster);

        /** Allow to change allocation strategy (automatic allocation of 
         *  cluster against no allocation)  
         */
        public void setAllocateCluster(boolean allocate_cluster);

        /** Return whether the iteration is finished */
        public boolean end();

        /** Increment iterator to point to next cluster of the link-list */
        public void incr() throws NoSuchElementException;

        /** Get current cluster */
        public Integer current();
    };

}
