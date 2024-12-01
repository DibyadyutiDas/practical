import java.util.Scanner;

public class SumInteractive {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide the number of inputs as a command-line argument.");
            return;
        }

        int totalNumbers = Integer.parseInt(args[0]);
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        System.out.println("Enter " + totalNumbers + " numbers:");
        for (int i = 0; i < totalNumbers; i++) {
            sum += sc.nextInt();
        }
        sc.close();
        System.out.println("Sum: " + sum);
    }
}