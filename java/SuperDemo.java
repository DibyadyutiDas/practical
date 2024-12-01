class Parent {
    int x = 10;

    Parent() {
        System.out.println("Parent class constructor");
    }

    void display() {
        System.out.println("Display method in Parent class");
    }
}

class Child extends Parent {
    int x = 20;

    Child() {
        super(); // Call Parent class constructor
        System.out.println("Child class constructor");
    }

    void display() {
        super.display(); // Call Parent class method
        System.out.println("Display method in Child class");
        System.out.println("Value of x in Parent class: " + super.x);
        System.out.println("Value of x in Child class: " + x);
    }
}

public class SuperDemo {
    public static void main(String[] args) {
        Child obj = new Child();
        obj.display();
    }
}