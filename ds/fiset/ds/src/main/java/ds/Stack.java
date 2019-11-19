package ds;

public class Stack<T> {
    private LinkedList<T> stack;

    public Stack() {
        stack = new LinkedList<T>();
    }    

    public void push(T data) { stack.add(data); }

    public T pop() { 
        if(stack.size()==0) throw new IndexOutOfBoundsException();
        return stack.remove(stack.size()-1);
    }
}