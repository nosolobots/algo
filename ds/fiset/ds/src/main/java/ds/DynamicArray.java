package ds;

import java.util.Iterator;

@SuppressWarnings("unchecked")
public class DynamicArray<T> implements Iterable {
    private static final int DEF_CAP = 16;
    private T[] data;

    private int capacity;
    private int len = 0;    // points to the first empty slot

    public DynamicArray() { this(DEF_CAP); }
    public DynamicArray(final int capacity) {
        if (capacity < 0)
            throw new IllegalArgumentException("Illegal capacity: " + capacity);
        this.capacity = capacity;
        data = (T[]) new Object[capacity];
    }

    public int size() {
        return len;
    }

    public boolean isEmpty() {
        return (len == 0);
    }

    public void add(final T obj) {
        if (len == capacity) {
            if (capacity == 0)
                capacity = 1;
            else
                capacity *= 2;
            final T[] new_data = (T[]) new Object[capacity];
            for (int i = 0; i < len; i++)
                new_data[i] = data[i];
            data = new_data;
        }
        data[len++] = obj;
    }

    public T get(final int index) {
        if (index < len && index >= 0)
            return data[index];
        else
            throw new IndexOutOfBoundsException();
    }

    public void clear() {
        for (int i = 0; i < len; i++)
            data[i] = null;
        len = 0;
    }

    public void remove(final int index) {
        if(index>=len || index<0) throw new IndexOutOfBoundsException();        
        else {
            for(int i=index; i<len-1; i++) data[i] = data[i+1];
            len--;
        }
    }

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