package ds;

public class DynamicArrayDemo {
    public static void main(String[] args) {
        DynamicArray<Integer> lista = new DynamicArray<Integer>(2);
        System.out.println(lista);
        lista.add(3);
        System.out.println(lista);
        lista.add(-5);
        lista.add(8);
        System.out.println(lista);
        try {
            lista.get(50);
        }
        catch(Exception e) {
            System.out.println(e);
        }
        for(Object n:lista) System.out.println((Integer)n);
    }
}