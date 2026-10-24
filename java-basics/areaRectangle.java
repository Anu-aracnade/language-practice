import java.util.Scanner;
public class areaRectangle{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Do you want to find the area of a rectangle (y/n): ");
        char fB = scanner.next().charAt(0);
        if (fB == 'y'){
        System.out.print("Enter the length of the rectangle: ");
        int length = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter the breadth of the rectangle: ");
        int breadth = scanner.nextInt();
        scanner.nextLine();
        int area = length*breadth;
        System.out.print("The Area of the rectangle having the length = "+length+" and the breadth = "+breadth+" is "+area);
        }
        else {
        System.out.print("Okay! Whatever");
        }
        scanner.close();
    }
}
// 1. scanner.next() reads the next word as a String
// 2. .charAt(0) grabs the character at index 0