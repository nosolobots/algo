package ds;

@SuppressWarnings("unchecked")
class ListNode<T> {
    T data;
    ListNode<T> next;
    ListNode<T> prev;

    ListNode(T obj) { data = (T)obj; } 
    public void setNext(ListNode<T> node) { next = node; }
    public void setPrev(ListNode<T> node) { prev = node; }
    public ListNode<T> getNext() { return next; }
    public ListNode<T> getPrev() { return prev; }
    public T getData() { return data; }

    @Override
    public String toString() { return "[" + data + "]"; }
}

public class LinkedList<T> {
    ListNode<T> head;
    ListNode<T> tail;
    int len;

    public int size() { return len; }
    public boolean isEmpty() { return (len==0); }    

    public void add(T data) {
        ListNode<T> newNode = new ListNode<T>(data);
        newNode.setPrev(tail);
        tail = newNode;
        len++;
    }

    private ListNode<T> getNode(int index) {
        int i=0;
        ListNode<T> node = head;
        while(i++<index) node = node.getNext();

        return node;
    }

    public T get(int index) {
        if(index>=len || index<0) throw new IndexOutOfBoundsException(); 
        
        return getNode(index).getData();
    }

    public void insert(T data, int index) {
        if(index>len || index<0) throw new IndexOutOfBoundsException();
        if(index==len) add(data);
        else {
            ListNode<T> newNode = new ListNode<T>(data);
            ListNode<T> oldNode = getNode(index);

            newNode.setNext(oldNode);
            newNode.setPrev(oldNode.getPrev());
            oldNode.setPrev(newNode);

            len++;
        }
    }

    public void remove(int index) {
        if(index>=len || index<0) throw new IndexOutOfBoundsException();
        ListNode<T> oldNode = getNode(index);
        if(index==len-1) tail = oldNode.getPrev();
        oldNode.getPrev().setNext(oldNode.getNext());
        oldNode.getNext().setPrev(oldNode.getPrev());
        len--;        
    }

    // TO-DO
    @Override
    public String toString() {
        String ret = "[" + len + ": ";
        if(len>0) {
            for(int i=0; i<len; i++ ) {
                ret += data[i];
                if(i<len-1) ret += ", ";
            }
        }
        return ret + "]";
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private int index = 0;
            
            @Override
            public boolean hasNext() { return (index<data.length); }
            
            @Override
            public T next() { return data[index++]; }
        };
    }    
}