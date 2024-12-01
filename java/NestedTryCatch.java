public class NestedTryCatch {
    public static void main(String[] args) {
        try {
            int[] arr = new int[3];
            try {
                arr[5] = 10; // ArrayIndexOutOfBoundsException
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Inner catch: Array index out of bounds");
            }
            int result = 10 / 0; // ArithmeticException
        } catch (ArithmeticException e) {
            System.out.println("Outer catch: Division by zero");
        }
    }
}