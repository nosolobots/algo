//: varios/Fibo.java

package varios;

import java.io.IOException;
import java.util.Scanner;

class Fibo {
    public static int fiboRec(int n) {
        if (n < 3)
            return 1;
        else
            return fiboRec(n - 1) + fiboRec(n - 2);
    }

    public static int[] fiboAr(int n) {
        int[] f = new int[n];

        for (int i = 0; i < n; i++) {
            if (i < 2)
                f[i] = 1;
            else
                f[i] = f[i - 1] + f[i - 2];
        }

        return f;
    }

    public static void main(String[] args) throws IOException {
        Scanner scn = new Scanner(System.in);

        System.out.print("\nHow many terms? ");
        int n = scn.nextInt();
        long mt;

        /*
        System.out.println("\nFiboRec(" + n + ") (Press [ret]):");
        System.in.read();

        mt = System.currentTimeMillis();
        for(int i=1; i<=n; i++) {
            System.out.print(fiboRec(i) + " ");
        }
        System.out.println();

        System.out.println("Time: " + (System.currentTimeMillis()-mt)/1000.0 + "s\n");
        */
        System.out.println("FiboAr(" + n + ") (Press [ret]):");
        System.in.read();

        mt = System.currentTimeMillis();
        for (int i : fiboAr(n)) {
            System.out.print(i + " ");
        }
        System.out.println();

        System.out.println("Time: " + (System.currentTimeMillis() - mt) / 1000.0 + "s\n");
    }
}
