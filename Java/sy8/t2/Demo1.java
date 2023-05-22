package t2;
public class Demo1 {
    public static void main(String[] args) {
        String a="ab123you";
        String regex = "\\D+";
        String str=a.replaceAll(regex,"");
        System.out.println("in:"+a);
        System.out.println("out:"+str);
    }
}
