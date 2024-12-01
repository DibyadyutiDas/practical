class Distance {
    private int feet;
    private int inches;

    public void setDistance(int feet, int inches) {
        this.feet = feet;
        this.inches = inches;
    }

    public void displayDistance() {
        System.out.println("Distance: " + this.feet + " feet " + this.inches + " inches");
    }
}

public class DistanceClasswiththisPointer {
    public static void main(String[] args) {
        Distance d = new Distance();
        d.setDistance(5, 10);
        d.displayDistance();
    }
}
