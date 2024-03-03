
class BinaryTest {
    public static void main(String[] args) {
        int[] numbersA = {1, 2, 3, 4, 5};
        if (binarySearch(numbersA,3)!=-1) {
            System.out.println("found");
        } else {
            System.out.println("not found");
        }
        if (binarySearch(numbersA,2)!=-1) {
            System.out.println("found");
        } else {
            System.out.println("not found");
        }

        int[] numbersB = {1, 2, 3, 5};
        if (binarySearch(numbersB,3)!=-1) {
            System.out.println("found");
        } else {
            System.out.println("not found");
        }

        int[] numbersC = {4, 4, 4, 4};
        if (binarySearch(numbersC,3)!=-1) {
            System.out.println("found");
        } else {
            System.out.println("not found");
        }

        int[] numbersD = {5, 7, 9, 10, 12};
        if (binarySearch(numbersD,13)!=-1) {
            System.out.println("found");
        } else {
            System.out.println("not found");
        }
    }

    /* 
     * requires: array not null
     * return: index of val if in array, -1 otherwise
     */
    static public int binarySearch(int[] array, int val) {
        return binarySearchHelper(array, val, 0, array.length-1); // -1
    }

    static public int binarySearchHelper(int[] array, 
                            int val, int start, int end) {
        int midInt = start  + ((end - start) / 2); 
        if (end < start) {
            return -1;
        }

        int midVal = array[midInt];
        if (val == midVal) {
            return midInt;
        } else if (val < midVal) {
            return binarySearchHelper(array, val, start, midInt-1);  // midInt-1 <- midVal
        } else {
            return binarySearchHelper(array, val, midInt+1, end);  // midInt+1 <- midVal+1
        }
    }
}