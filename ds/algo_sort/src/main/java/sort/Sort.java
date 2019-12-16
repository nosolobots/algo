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
        int[] mer = merge(ar, 0, ar.length-1);
        for(int i=0; i<ar.length;i++) ar[i] = mer[i];
    }

    private static int[] merge(int[] ar, int ini, int end) {
        /**
         * ini, first index of the array
         * end, last index of the array
         */
        int len = end - ini + 1;
        
        if(len==1) return new int[]{ ar[ini] };
        if(len==2) {
            if(ar[ini]<=ar[end]) 
                return new int[]{ ar[ini], ar[end] };
            else 
                return new int[]{ ar[end], ar[ini] };   // swap
        }

        int m = ini + len/2;    // mid position

        int[] left = merge(ar, ini, m-1);
        int[] right = merge(ar, m, end);

        int[] mar = new int[len];
        int i, l, r;
        // add left[] and right[] items until one of them is empty
        for(i=l=r=0; l<left.length && r<right.length; i++) 
            if(left[l]<=right[r]) 
                mar[i] = left[l++];
            else 
                mar[i] = right[r++];
        // add the rest (of left[] or right[])
        for(; i<len; i++) 
            if(l<left.length) 
                mar[i] = left[l++];
            else
                mar[i] = right[r++];

        return mar;
    }
}