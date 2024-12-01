public class BoxingandUnboxing {
    public static void main(String[] args) {
        // Boxing
        Integer boxed = Integer.valueOf(10);
        System.out.println("Boxed value: " + boxed);

        // Unboxing
        int unboxed = boxed.intValue();
        System.out.println("Unboxed value: " + unboxed);
    }
}
