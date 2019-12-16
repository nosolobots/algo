package sort;

import java.util.Arrays;

class SortDemo {
    public static void print(int[] ar) {
        System.out.print("{ ");
        for(int n:ar) System.out.print(n + " ");
        System.out.println(" }");
    }
    public static void main(String[] args) {
        int[] ar_test = { 19, 31, -2, 5, 42, 1, 22 };       
        int[] ar;

        System.out.println("\nBubble sort:");
        ar = Arrays.copyOf(ar_test, ar_test.length);
        print(ar);

        Sort.bubbleSort(ar);
        print(ar);

        System.out.println("\nSelection sort:");
        ar = Arrays.copyOf(ar_test, ar_test.length);
        print(ar);

        Sort.selectionSort(ar);
        print(ar);

        System.out.println("\nInsertion sort:");
        ar = Arrays.copyOf(ar_test, ar_test.length);
        print(ar);

        Sort.insertionSort(ar);
        print(ar);

        System.out.println("\nMerge sort:");
        ar = Arrays.copyOf(ar_test, ar_test.length);
        print(ar);

        Sort.mergeSort(ar);
        print(ar);        
    }
}