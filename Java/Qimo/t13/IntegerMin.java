package t13;
//3. 编写程序，输出
// 满足1+2+3+...+n>10000的最小正整数n,程序文件命名为“IntegerMin.java”。
public class IntegerMin {
    public static void main(String[] args) {
        int sum=0;
        int i=0;
        while (sum<10000){
            sum+=++i;
        }
        System.out.println(i);
    }
}
