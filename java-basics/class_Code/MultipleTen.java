package class_Code;

public class MultipleTen {
    public static void main(String[] args){
        int N = 2;
        System.out.println("Our selected number is "+ N);
        for (int i=1;i<=10;++i){
            System.out.println(N+" * "+i+" = "+(N*i));
            System.out.println("\n");
        }
    }
}
