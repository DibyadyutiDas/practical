import java.util.Scanner;

public class InputMessage {
    public static String getMessage() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a message: ");
        return sc.nextLine();
    }
}