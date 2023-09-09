package t20;
import java.util.*;
//编程实现输入一行字符串，分别统计出其中
// 英文字母、空格、数字和其它字符的个数。程序文件命名为“Counter.java”。
public class Counter {
    public static void main(String[] args) {
        int zm=0,kg=0,sz=0,qt=0;
        Scanner read=new Scanner(System.in);
        String s = read.nextLine();
        char[] a =s.toCharArray();
        for(int i=0;i<a.length;i++){
            if ((a[i]>='a'&&a[i]<='z')||(a[i]>='A' && a[i]<='Z'))    zm++;
            else if (a[i]>='0' && a[i]<='9')   sz++;
            else if (a[i]==' ')  kg++;
            else  qt++;
        }
        System.out.println("字符串["+s+"]中");
        System.out.println("字母有"+zm+"个");
        System.out.println("数字有"+sz+"个");
        System.out.println("空格有"+kg+"个");
        System.out.println("其他字符有"+qt+"个");
    }
}
