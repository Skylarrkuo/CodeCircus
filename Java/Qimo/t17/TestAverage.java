package t17;
//7.编写程序，实现以下功能：
//设计一个应用程序，该应用程序用接口实现计算三个数的算术平均数和几何平均数，
// 例如有两个数a,b,c其算术平均数为：（a+b+c）/3;
// 其几何平均数为：\sqrt[3]{a\ast b\ast c}。要求如下：
//	设计一个接口（CompurerAverage），该接口有一个抽象方法average（）
//	要求实现该接口的类完成平均数的计算。
//	设计一个ArithmeticAverage类实现算术平均数的运算。
//	设计一个GeometryAverage类实现几何平均数的运算。
//	设计一个TestAverage测试类完成测试。
public class TestAverage {
    public static void main(String[] args) {
        ArithmeticAverage A =new ArithmeticAverage(3.0,4.0,5.0);
        GeometryAverage B =new GeometryAverage(3.0,4.0,5.0);
        System.out.println("3,4,5的算数平均数为"+A.average());
        System.out.println("3,4,5的几何平均数为"+B.average());
    }
}
interface CompurerAverage{
    double average();
}
class ArithmeticAverage implements CompurerAverage{
    double a,b,c;
    public ArithmeticAverage(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public double average() {
        return (a+b+c)/3;
    }
}
class GeometryAverage implements CompurerAverage{
    double a,b,c;
    public GeometryAverage(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public double average() {
        return Math.pow(a*b*c,1.0/3.0);
    }
}