package t2;
//2.编写一个Java程序，输出从100-200 之间（包括100和200）的所有质数，以空格分隔方式输出这些数字，程序文件命名为“PrimeNumer.java”。
//提示：质数为大于1的自然数中，除了1和它本身以外不能被其他数整除的自然数。例如2,3,5,7……
public class PrimeNumer {
    public static void main(String[] args) {
        for(int i =100,t=0;i<=200;i++,t=0){
            int j;
            for(j=2;j<(int)(i/2);j++){
                if(i%j!=0)
                    t++;
                else
                    break;
            }
            if(j==(int)(i/2))
                System.out.printf("%d ",i);
        }
    }
}
