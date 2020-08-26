public class PeakFinder {
    public static int traverseFindPeak(int[] a) {
        if(a.length==1) return -1; // Check if thre's only one member
        if(a[0]>a[1]) return 0; // Check if first element is the peak
        if(a[a.length-1]>a[a.length-2]) return a.length-1; // Check if last member is the peak
        for(int i=1; i<a.length-1; i++) 
            if(a[i]>a[i-1] && a[i]>a[i+1]) return i;
        return -1;  // No peak
    }

}