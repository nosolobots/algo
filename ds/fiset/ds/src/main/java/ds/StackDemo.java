package ds;

public class StackDemo {
    public static void main(String[] args) {
        Stack<Integer> pila = new Stack<>();
        pila.push(3);
        pila.push(5);
        System.out.println(pila.pop());
        pila.push(7);
        pila.push(-2);
        System.out.println(pila.pop());
        System.out.println(pila.pop());
        System.out.println(pila.pop());
    }
}
