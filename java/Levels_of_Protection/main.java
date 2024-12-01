import protection.ParentClass;
import protection.SubClass;

public class Main {
    public static void main(String[] args) {
        ParentClass obj = new ParentClass();
        obj.display();

        SubClass subObj = new SubClass();
        subObj.displaySubClass();
    }
}