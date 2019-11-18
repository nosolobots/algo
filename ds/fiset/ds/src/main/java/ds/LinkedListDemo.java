package ds;

public class LinkedListDemo {
    public static void main(String[] args) {
        LinkedList<Integer> lista = new LinkedList<Integer>();
        System.out.println("lista inicial:");
        System.out.println(lista);
        System.out.println("Añadimos 3...");
        lista.add(3);
        System.out.println(lista);
        System.out.println("Añadimos -5 y 8");
        lista.add(-5);
        lista.add(8);
        System.out.println(lista);
        System.out.println("Insertamos 4 en posición 2");
        lista.insert(4, 2);
        System.out.println(lista);
        System.out.println("Eliminamos -5");
        lista.remove(1);
        System.out.println(lista);
    }
}