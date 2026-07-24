package class_Code;

class Assignment {
    static void assign(){
        int a = 12;
        int b = 13;
        System.out.println(a=14);
    }
    static void update(){
        int a = 14;
        int b = 25;
        System.out.println(a += 5);
        System.out.println(b -= 6);
    }
    public static void main(String[] args){
        assign();
        update();
    }
}
