package t4;
import java.util.*;


public class Demo3 {
    public static void main(String[] args) {
        String a="欢迎光临美好生活超市,你所买的苹果20.5元，梨10.6元,铅笔5.8元，香蕉30.1元，矿泉水40.8元。";
        System.out.println(a);
        String regex="[^0123456789.]";
        double sum=0;
        a=a.replaceAll(regex,"#");
        StringTokenizer ty=new StringTokenizer(a,"#");
        while (ty.hasMoreTokens()){
            String t= ty.nextToken();
            sum=sum+Double.parseDouble(t);
        }
        System.out.println("该同学一共消费："+sum+"元");
    }
}
