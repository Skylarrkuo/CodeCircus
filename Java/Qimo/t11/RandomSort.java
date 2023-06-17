package t11;
import java.util.*;
//1. 产生10个1-100之间的随机整数输出，
// 并把这10个数按从小到大的顺序输出，程序文件命名为“RandomSort.java”。
public class RandomSort {
    public static void main(String[] args) {
        Random random = new Random();
        int[] a = new int[10];
        for(int i=0;i<10;i++){
            a[i]= random.nextInt(90)+10;
        }
        Arrays.sort(a);
        for(int i=0;i<10;i++){
            System.out.printf("%d ",a[i]);
        }
    }
}
