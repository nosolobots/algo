package ds;
import java.util.Iterator;

@SuppressWarnings("unchecked")
class ListNode<T> {
    T data;
    ListNode<T> next;
    ListNode<T> prev;

    ListNode(final T obj) {
        data = (T) obj;
    }

    public void setNext(final ListNode<T> node) {
        next = node;
    }

    public void setPrev(final ListNode<T> node) {
        prev = node;
    }

    public ListNode<T> getNext() {
        return next;
    }

    public ListNode<T> getPrev() {
        return prev;
    }

    public T getData() {
        return data;
    }

    @Override
    public String toString() {
        return "[" + data + "]";
    }
}

public class LinkedList<T> implements Iterable {
    ListNode<T> head;
    ListNode<T> tail;
    int len;

    public int size() {
        return len;
    }

    public boolean isEmpty() {
        return (len == 0);
    }

    public void add(final T data) {
        final ListNode<T> newNode = new ListNode<T>(data);

        if (len == 0) head = newNode;
        else tail.setNext(newNode);

        newNode.setPrev(tail);
        tail = newNode;

        len++;
    }

    private ListNode<T> getNode(final int index) {
        if (index == 0)
            return head;
        if (index == len - 1)
            return tail;

        ListNode<T> node = head;
        int i = 0;
        while (i++ < index)
            node = node.getNext();

        return node;
    }

    public T get(final int index) {
        if (index >= len || index < 0)
            throw new IndexOutOfBoundsException();

        return getNode(index).getData();
    }

    public void insert(final T data, final int index) {
        if (index > len || index < 0)
            throw new IndexOutOfBoundsException();
        if (index == len)
            add(data);
        else {
            final ListNode<T> newNode = new ListNode<T>(data);
            final ListNode<T> oldNode = getNode(index);

            newNode.setNext(oldNode);
            if (index == 0)
                head = newNode;
            else {
                newNode.setPrev(oldNode.getPrev());
                oldNode.getPrev().setNext(newNode);
            }
            oldNode.setPrev(newNode);

            len++;
        }
    }

    public T remove(final int index) {
        if (index >= len || index < 0)
            throw new IndexOutOfBoundsException();
        ListNode<T> old, prev, next;

        old = getNode(index);
        prev = old.getPrev();
        next = old.getNext();

        if (index == len - 1)
            tail = prev;
        if (index == 0)
            head = next;

        if (prev != null)
            prev.setNext(next);
        if (next != null)
            next.setPrev(prev);

        len--;

        return old.getData();
    }

    // TO-DO
    @Override
    public String toString() {
        String ret = "[" + len + ": ";
        ListNode<T> node = head;
        int i = 0;
        while (node != null) {
            ret += node.getData();
            if (++i < len)
                ret += ", ";
            node = node.getNext();
        }
        return ret + "]";
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private final ListNode<T> node = head;
            
            @Override
            public boolean hasNext() { return (node.getNext()!=null); }
            
            @Override
            public T next() { return node.getNext().getData(); }
        };
    }    
}