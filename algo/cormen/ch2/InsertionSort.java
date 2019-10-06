//: cormen/ch2/InsertionSort.java
package cormen.ch2;

class InsertionSort {
    // integer primitive sorting method
    public static void iSort(int[] ar) {
        for(int i=1, j, key; i<ar.length; i++) {
            key = ar[i];
            j = i - 1;
            while(j>=0 && ar[j] > key) {
                ar[j + 1] = ar[j];
                ar[j] = key;
                j--;
            }
        }
    }

    // generics implementation
    public static <T extends Comparable<T>> void sort(T[] ar) {
        for(int i=1, j; i<ar.length; i++) {
            T key = ar[i];
            j = i - 1;
            while(j>=0 && ar[j].compareTo(key) > 0) {
                ar[j + 1] = ar[j];
                ar[j] = key;
                j--;
            }
        }        
    }
}

