class Demo {
    public int publicVar = 10;
    private int privateVar = 20;

    public void showPublic() {
        System.out.println("Public variable: " + publicVar);
    }

    private void showPrivate() {
        System.out.println("Private variable: " + privateVar);
    }
}

public class Public_Private_FinalKeyword {
    public static void main(String[] args) {
        Demo obj = new Demo();
        obj.showPublic();
        // obj.showPrivate(); // Error: Cannot access private method
        obj.publicVar = 30; // Can modify
        // obj.privateVar = 40; // Error: Cannot access private variable
    }
}