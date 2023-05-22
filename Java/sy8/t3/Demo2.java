package t3;
import java.util.*;
import java.util.Scanner;

public class Demo2 {
    public static void main(String[] args) {
        double sum=0;
        String a= "数学87分，物理76分，英语96分";
        Scanner ty = new Scanner(a);
        ty.useDelimiter("\\D+");
        while (ty.hasNext()){
            double t=ty.nextDouble();
            sum=sum+t;
        }
        System.out.println("成绩："+a);
        System.out.println("总分为："+sum);
        System.out.println("平均分为:"+sum/3);
    }
}
