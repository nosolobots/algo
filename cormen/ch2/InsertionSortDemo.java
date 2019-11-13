//: cormen/ch2/InsertionSort.java

package cormen.ch2;

class InsertionSortDemo {
    public static <T> void printAr(T[] ar) {
        for(T n:ar){
            System.out.print(n + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Integer[] ar = {5, 2, 4, 6, 1, 3};
        
        printAr(ar);
        
        InsertionSort.sort(ar);

        printAr(ar);
    }
}