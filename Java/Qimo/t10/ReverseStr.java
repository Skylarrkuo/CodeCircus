package t10;
import java.util.Scanner;
public class  ReverseStr {
    public static void main(String[] args) {
        String s;
        String regex = "\s+";
        String[] a;
        Scanner read=new Scanner(System.in);
        s=read.nextLine();
        a=s.split(regex);
        for(int i=a.length-1;i>=0;i--){
            System.out.printf("%s ",a[i]);
        }
    }
}
