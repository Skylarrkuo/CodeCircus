package t1;
//1.编写一个Java程序，求1!+2!+…+10!的值，程序文件命名为“FactoriesSum.java”。
public class FactoriesSum {
    public static void main(String[] args) {
        int sum=0;
        for(int i=1,a=1;i<=10;i++,a=1){
            for(int j=1;j<=i;j++){
                a*=j;
            }
            sum+=a;
        }
        System.out.println("1!+2!+…+10!="+sum);
    }
}