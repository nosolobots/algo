package ds;

public class Stack<T> {
    private LinkedList<T> stack;

    public Stack() { stack = new LinkedList<T>(); }    
    public Stack(T data) {
        this();
        stack.add(data);
    }

    public int size() { return stack.size(); }
    
    public void push(T data) { stack.add(data); }

    public T pop() { 
        if(stack.size()==0) throw new IndexOutOfBoundsException();
        return stack.remove(stack.size()-1);
    }

    public T peek() { 
        if(stack.size()==0) throw new IndexOutOfBoundsException();
        return stack.get(stack.size() - 1);
    }
}