import java.util.Scanner;
public class input {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("What's your name ?....");
        String name = scanner.nextLine();
        System.out.println("Hey! nice to meet you " + name);
    }
}
