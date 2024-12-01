package protection;

public class SubClass extends ParentClass {
    public void displaySubClass() {
        System.out.println("Accessing from SubClass:");
        System.out.println("Public: " + publicVar);
        System.out.println("Protected: " + protectedVar);
        System.out.println("Default: Not accessible in different package");
        // System.out.println("Private: Not accessible");
    }
}