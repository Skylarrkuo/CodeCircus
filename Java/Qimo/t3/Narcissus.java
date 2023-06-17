package t3;
//3.编写一个Java程序，求100-999之间的水仙花数，程序文件命名为“Narcissus.java”。
// 提示：水仙花数为一个数的每一位数字的立方之和等于这个数，如数字153，1^3+5^3+3^3=153，以空格分隔输出这些数字。
public class Narcissus {
    public static void main(String[] args) {
        for(int i=100;i<=999;i++){
            int a=i%10;
            int b=i/10%10;
            int c=i/100;
            if(Math.pow(a,3)+Math.pow(b,3)+Math.pow(c,3)==i)
                System.out.printf("%d ",i);
        }
    }
}
