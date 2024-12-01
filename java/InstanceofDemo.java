class Parent {}
class Child extends Parent {}

public class InstanceofDemo {
    public static void main(String[] args) {
        Parent obj1 = new Parent();
        Child obj2 = new Child();

        System.out.println("obj1 instanceof Parent: " + (obj1 instanceof Parent)); // true
        System.out.println("obj2 instanceof Parent: " + (obj2 instanceof Parent)); // true
        System.out.println("obj1 instanceof Child: " + (obj1 instanceof Child));  // false
        System.out.println("obj2 instanceof Child: " + (obj2 instanceof Child));  // true
    }
}