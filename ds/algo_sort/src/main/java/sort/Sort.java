package sort;

import java.util.Arrays;

public class Sort {
    public static void bubbleSort(int[] ar) {
        int n = ar.length-1;
        boolean swap = true;
        while(swap) {
            swap = false;
            for(int i=0, t; i<n-1; i++) {
                if(ar[i]>ar[i+1]) {
                    // swap
                    t = ar[i];
                    ar[i] = ar[i+1];
                    ar[i+1] = t;
                    swap = true;
                }
            }
            n--;
        }
    }

    public static void insertionSort(int[] ar) {
        for(int i=1, j=i-1, v; i<ar.length; i++, j=i-1) {
            v = ar[i];
            while(j>=0 && v<ar[j]) {
                ar[j+1]=ar[j];
                j--;
            }
            ar[j+1] = v;
        }
    }

    public static void selectionSort(int[] ar) {
        for(int n=ar.length-1, maxi; n>=0; n--) {
            maxi = 0;   // index of max value

            // find max
            for(int i=1; i<=n; i++) {
                if(ar[i]>ar[maxi])
                    maxi = i;
            }
            
            // swap value
            if(maxi != n) {
                int t = ar[n];
                ar[n] = ar[maxi];
                ar[maxi] = t;
            }
        }
    }

    public static void mergeSort(int[] ar) {
        mergeSort(ar, 0, ar.length-1);
    }

    private static void mergeSort(int[] ar, int ini, int end) {
        /**
         * ini, first index of the array
         * end, last index of the array
         */
        int len = end - ini + 1;
        
        if(len==1) return;          // partition of one element (already sorted)

        int m = ini + len/2;        // mid position

        mergeSort(ar, ini, m-1);    // left side
        mergeSort(ar, m, end);      // right side

        merge(ar, ini, m, end);
    }

    private static void merge(int[] ar, int ini, int m, int end) {
        if (ar[m-1]<=ar[m]) return; // the two partitions are already sorted
        
        int i = 0, l = ini, r = m;
        
        int[] temp = new int[end - ini + 1]; // temporary array to merge partitions
        
        // add the smaller of both partitions in each iteration
        while(l<m && r<=end) 
            temp[i++] = (ar[l]<ar[r]) ?  ar[l++] : ar[r++];     

        // If there are still elements in the left side, add them
        // We don't have to check for the right side. If there were elements to add, 
        // they are already sorted
        while(l<m) temp[i++] = ar[l++];    
                                    
        // copy temp data in its final position
        System.arraycopy(temp, 0, ar, ini, i);
        //for(int j=0; j<i; j++) ar[ini+j] = temp[j];
    }
}