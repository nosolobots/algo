package ds;

public class QueueDemo {
    public static void main(String[] args) {
        Queue<Integer> cola = new Queue<>();
        cola.enqueue(3);
        cola.enqueue(5);
        System.out.println(cola.dequeue());
        cola.enqueue(7);
        cola.enqueue(-2);
        System.out.println(cola.peek() + " (peeking)");
        System.out.println(cola.dequeue());
        System.out.println(cola.dequeue());
        System.out.println(cola.dequeue());
    }
}
