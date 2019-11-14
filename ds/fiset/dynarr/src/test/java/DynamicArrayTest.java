import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class DynamicArrayTest {
    @Test 
    public void evaluaCreate() {
        DynamicArray<Integer> list = new DynamicArray<Integer>(2);
        list.add(3);
        list.add(-5);
        list.add(8);
        assertEquals("[3: 3, -5, 8]", list.toString());
    }
}