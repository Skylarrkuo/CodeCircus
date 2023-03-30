import java.util.Scanner;
public class Student {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        Bank stu= new Bank("10086","张三","2077-3-1",1008677,99999);
        System.out.println("账户信息：");
        stu.info();
        int i=0;
        System.out.println("按1回车进行存钱，按2回车进行取钱，按3回车退出操作");
        while (s.hasNext()) {
            i= s.nextInt();
            if (i == 1) {
                System.out.println("输入要存的金额");
                stu.cun(s.nextDouble());
                System.out.println("按1回车进行存钱，按2回车进行取钱，按3回车退出操作");
            } else if (i == 2) {
                System.out.println("输入要取的金额");
                stu.qu(s.nextDouble());
                System.out.println("按1回车进行存钱，按2回车进行取钱，按3回车退出操作");
            }else if(i==3) break;
        }
        System.out.println("操作后的账户信息：");
        stu.info();

    }
}
