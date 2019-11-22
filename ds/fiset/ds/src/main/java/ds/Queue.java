package ds;

public class Queue <T> {
    LinkedList<T> queue;

    public Queue() { queue  = new LinkedList<T>(); }

    public Queue(T data) { 
        this();
        queue.add(data);
    }

    public int size() { return queue.size(); }

    public void enqueue(T data) { queue.add(data); }

    public T dequeue() { return queue.remove(0); }

    public T peek() { return queue.get(0); }
}