class StaticDemo {
    public static int sum(int... numbers) {
        int total = 0;
        for (int num : numbers) {
            total += num;
        }
        return total;
    }
}

public class StaticFunctionsandVariableLengthArguments {
    public static void main(String[] args) {
        System.out.println("Sum: " + StaticDemo.sum(1, 2, 3, 4, 5));
    }
}