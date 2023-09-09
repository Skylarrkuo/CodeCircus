package t18;
import java.util.*;
//8. 编写程序，实现以下功能：
//使用Scanner类的实例解析字符串
// “欢迎光临美好生活超市,你所买的苹果20.5元，梨20元,铅笔5.8元，香蕉30.5元，矿泉水20.8元。”
// 中的金额，并计算出此次在超市中花费的总额。要求如下：
//（1）设计一个givePriceSum类用于解析字符串中的金额。
//（2）设计一个PriceSumTest测试类测试结果。
public class PriceSumTest {
    public static void main(String[] args) {
        String str = "欢迎光临美好生活超市,你所买的苹果20.5元，梨20元,铅笔5.8元，香蕉30.5元，矿泉水20.8元。";
        givePriceSum PriceSum =new givePriceSum();
        System.out.println(str);
        System.out.println("总花费："+PriceSum.PriceSum(str));
    }
}
class givePriceSum{
    double PriceSum(String str){
        double sum=0;
        Scanner read = new Scanner(str);
        read.useDelimiter("[^0-9.]+");
        while (read.hasNext()){
            try {
                sum+= read.nextDouble();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        return sum;
    }
}