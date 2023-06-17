package t4;
//4.编写一个Java程序，输出1949年-2023年内的闰年，要求按行输出，一行5个年份，用空格分隔，程序文件命名为“LeapYear.java”。
public class LeapYear {
    public static void main(String[] args) {
        for (int i = 1949,a=0; i <= 2023; i++) {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                System.out.printf("%d\t", i);
                a++;
                if(a%5==0){
                    System.out.print("\n");
                }
            }
        }
    }
}