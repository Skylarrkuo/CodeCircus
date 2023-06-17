package t6;
//2.编写程序，实现以下功能：
//（1）定义一个形状的抽象类：Shape，包含两个抽象方法：
//①getArea：获取形状的面积；
//② getPerimeter：获取形状的周长；
//（2）再定义两个子类-圆形类和矩形类：Circle和Rectangle，分别继承自Shape类。
//① Circle类中需要包含一个私有变量-半径radius和一个构造方法，
// 构造方法带有一个参数radius，通过构造方法可以设置矩形的半径；并且需要实现getArea和getPerimeter方法分别获取圆形的面积和周长。
//② Rectangle类中需要包含两个私有变量-长度length和宽度width；
// 以及构造方法，构造方法带有两个参数length和width，通过构造方法可以设置矩形的长和宽；并且需要实现getArea和getPerimeter方法分别获取矩形的面积和周长。
//3.最后，编写一个测试类Test，在main方法中创建一个Circle和一个Rectangle对象，并分别调用它们的getArea和getPerimeter方法，打印它们的面积和周长。
public class Test {
    public static void main(String[] args) {
    Circle Y=new Circle(5);
        System.out.println("圆的面积为"+Y.getArea()+",周长为"+Y.getPerimeter());
    Rectangle J=new Rectangle(4,3);
        System.out.println("矩形的面积为:"+J.getArea()+",周长为:"+J.getPerimeter());
    }
}
abstract class Shape{

    public abstract double getArea();
    public abstract double getPerimeter();
}
class Circle extends Shape{
    private double radius;
    final public  double PI=3.1415926;
    Circle(double radius){
        this.radius=radius;
    }
    public double getArea() {
        return Math.pow(this.radius,2)*PI;
    }

    public double getPerimeter() {
        return 2*radius*PI;
    }
}

class Rectangle extends Shape{
    private double length,width;
    Rectangle(double length,double width){
        this.length=length;
        this.width=width;
    }
    public double getArea() {
        return this.length*this.width;
    }

    public double getPerimeter() {
        return (this.length+this.width)*2;
    }
}