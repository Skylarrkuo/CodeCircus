package t12;
//2. 编写应用程序，使用for循环语句
// 计算5+55+555+5555+...的前10项之和,程序文件命名为“SequenceSum.java”。
public class SequenceSum {
    public static void main(String[] args) {
        long sum=0;
        for(int i=1;i<=10;i++){
            sum+=(long)((5.0/9.0)*Math.pow(10,i));
        }
        System.out.println("5+55+555+5555+...的前10项之和为"+sum);
    }
}
