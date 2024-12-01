class Distance {
    private int feet;
    private int inches;

    // Constructor
    public Distance(int feet, int inches) {
        this.feet = feet;
        this.inches = inches;
    }

    // Cloning Method
    public Distance clone() {
        return new Distance(this.feet, this.inches);
    }

    public void displayDistance() {
        System.out.println("Distance: " + feet + " feet " + inches + " inches");
    }
}

public class DistanceClasswithConstructorsandCloning {
    public static void main(String[] args) {
        Distance d1 = new Distance(5, 10);
        Distance d2 = d1; // Reference
        Distance d3 = d1.clone(); // Clone

        System.out.println("Original:");
        d1.displayDistance();
        System.out.println("Reference:");
        d2.displayDistance();
        System.out.println("Clone:");
        d3.displayDistance();
    }
}
