import java.text.*;
import java.util.*;
public class Demo {
    public static void main(String[] args) {
        SimpleDateFormat ft = new SimpleDateFormat ("yyyy-MM-dd");
        String date1 =args[0];
        String date2 =args[1];
        Date t1,t2;
        try {
            t1 = ft.parse(date1);//格式化第一个日期
            t2 = ft.parse(date2);//格式化第二个日期
            System.out.println(date1+"到"+date2+"间隔了"+(t2.getTime()-t1.getTime())/86400000+"天");
        } catch (ParseException e) {
        }
    }
}

