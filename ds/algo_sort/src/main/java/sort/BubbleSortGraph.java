import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Random;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;

class Surface extends JPanel implements ActionListener {

    private final int DELAY = 5000;
    private Timer timer;
    private int[] data;
    private int[] unsorted;
    private boolean init;

    public Surface() {
        setDoubleBuffered(true);
        init = true;
        initData();
        initTimer();
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

    private void initData() {
        int w = (BubbleSortGraph.WIDTH-30)/2;
        int h = (BubbleSortGraph.HEIGHT-30)/2;
        
        data = new int[w];
        unsorted = new int[w];
        int[] yval = new int[h];

        for(int i=0; i<h; i++) { yval[i] = i*2; }
        
        // shuffle
        shuffle(yval);
        
        for(int i=0; i<w; i++) {
            unsorted[i] = data[i] = yval[i];
        }
    }

    private void sort() {
        int i, temp, n = data.length - 1;
        boolean swap = true;
        while(swap) {
            swap = false;
            for(i=0; i<n; i++) {
                if(data[i]<data[i+1]) {
                    swap = true;
                    temp = data[i+1];
                    data[i+1] = data[i];
                    data[i] = temp;

                    doDrawingData(this.getGraphics());
                    //revalidate();
                }
            }
            n--;
        }
    }

    private void initTimer() {
        timer = new Timer(DELAY, this);
        timer.start();
    }
    
    public Timer getTimer() {        
        return timer;
    }

    private void doDrawingData(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;

        super.paintComponent(g2d);
        //g2d.clearRect(0, 0, 500, 500);        

        g2d.setPaint(Color.blue);

        for (int i = 0; i < data.length; i++) {
            g2d.drawRect(i*2, data[i], 2, 2);
        }
    }    



    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        doDrawingData(g);
        System.out.println("repaint");
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(init) {
            init = false;
            System.out.println("init sort");
            sort();
        } else {
            for(int i=0; i<data.length; i++) {
                data[i] = unsorted[i];
            }
            repaint();
            init = true;
        }
    }
}

public class BubbleSortGraph extends JFrame {
    public static final int WIDTH = 500;
    public static final int HEIGHT = 500;

    public BubbleSortGraph() {
        initUI();
    }

    private void initUI() {
        final Surface surface = new Surface();
        add(surface);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                Timer timer = surface.getTimer();
                timer.stop();
            }
        });

        setTitle("Points");
        setSize(WIDTH-25, HEIGHT);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {

                BubbleSortGraph bubble = new BubbleSortGraph();
                bubble.setVisible(true);
            }
        });
    }
}