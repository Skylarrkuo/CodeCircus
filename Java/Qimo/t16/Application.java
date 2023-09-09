package t16;
//6.编写程序，实现以下功能：
//设计一个计算柱体应用程序，希望该应用程序可以计算不同柱体的体积，要求如下：
//(1)	首先设计一个抽象类Geometry（几何图形）类，
// 在该抽象类中定义一个抽象getArea()方法.
//(2)	然后设计PillarL（柱体）类，
// 该类的对象调用getVolume()方法计算柱体的体积，
//(3)	分别设计Circle（圆）类和Rectangle（矩形）类
// 和Triangle（三角形）类作为Geometry类的子类。
//(4)	最后设计Application测试类分别求出圆柱的体积，
// 四棱柱的体积，三棱柱的体积。
//提示：三角形的面积可以由海伦公式计算。
//海伦公式：如果一个三角形的三边长为a，b，c，设p=（a+b+c）/2
public class Application {
    public static void main(String[] args) {
        Circle circle = new Circle(5);
        Rectangle rectangle = new Rectangle(4,3);
        Triangle triangle =new Triangle(3,4,5);
        Pillar A = new Pillar(circle,5);
        System.out.println("圆柱的体积为："+A.getVolmume());
        A.bottom=rectangle;
        System.out.println("四棱柱的体积为："+A.getVolmume());
        A.bottom=triangle;
        System.out.println("三棱柱的体积为："+A.getVolmume());
    }
}
class Pillar{
    Geometry bottom;
    double height;
    public Pillar(Geometry bottom, double height) {
        this.bottom = bottom;
        this.height = height;
    }
    double getVolmume(){
        return bottom.getArea()*height;
    }
}
abstract class Geometry{
    abstract double getArea();
}

class Circle extends Geometry{
    double r;
    final double PI = 3.1415926;
    public Circle(double r) {
        this.r = r;
    }
    double getArea() {
        return PI*Math.pow(r,2);
    }
}
class Rectangle extends Geometry {
    double a,b;
    public Rectangle(double a, double b) {
        this.a = a;
        this.b = b;
    }
    double getArea() {
        return a*b;
    }
}
class Triangle extends Geometry{
    double a,b,c;
    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    double getArea() {
        double p=(a+b+c)/2;
        return Math.sqrt(p*(p-a)*(p-b)*(p-c));
    }
}