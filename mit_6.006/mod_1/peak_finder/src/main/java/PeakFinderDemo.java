// use -Xms8G Xmx8G for 1.000.000.000 input elements
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

class PeakFinderDemo {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        System.out.print("Elements? ");
        int numE = cin.nextInt();

        System.out.println("Peak (-1 for none)?");
        int peak = cin.nextInt();

        // traverseFindPeak
        System.out.println("\n---> traverseFindPeak():\n");

        // Test - No peak
        System.out.println("- Test -");
        System.out.println("Elements: " + numE);
        
        int[] ta = new int[numE];
        if(peak!=-1) ta[peak] = 1;
        testTraverseFindPeak(ta);

        System.out.println();
    }

    private static void testTraverseFindPeak(int[] a) {
        long tn = System.nanoTime();
        long tm = System.currentTimeMillis();
        System.out.println("Peak: " + PeakFinder.traverseFindPeak(a));
        System.out.println("Time (ns): " + (System.nanoTime()-tn)*1e-9 + " s");
        System.out.println("Time (ms): " + (System.currentTimeMillis()-tm)*1e-3 + " s");
    }
}
