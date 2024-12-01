class OverloadDemo {
    void show(int x) {
        System.out.println("Integer: " + x);
    }

    void show(double x) {
        System.out.println("Double: " + x);
    }
}

public class FunctionOverloadingwithTypeConversion {
    public static void main(String[] args) {
        OverloadDemo obj = new OverloadDemo();
        obj.show(10); // Exact match
        obj.show(10.5); // Exact match
        obj.show('A'); // Type conversion (char to int)
    }
}
