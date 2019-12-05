import java.util.Random;

public class Shuffle {
    private static void display(int[] ar) {
        for(int n:ar) System.out.print(n + " ");
        System.out.println();
    }

    private static void shuffle(int[] ar) {
        Random r = new Random();
        for(int i=ar.length-1, j, t; i>0; i--) {
            j = r.nextInt(i+1);
            t = ar[j];
            ar[j] = ar[i];
            ar[i] = t;
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[10];

        for(int i=0; i<nums.length; i++) { nums[i] = i; }
        
        display(nums);
        shuffle(nums);
        display(nums);
    }
}