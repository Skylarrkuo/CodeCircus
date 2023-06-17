package t14;
//4.编写程序，实现以下功能：
//创建一个桌子（Table）类，该类中有桌子名称（name）
// 重量（weight）、桌面宽度（width）、长度（length）
// 和桌子高度（height）属性以及以下几个方法：
//（1）无参构造方法：默认值初始化所有成员变量；
//（2）有参构造方法：根据参数初始化成员变量；
//（3）area():计算桌面的面积；
//（4）display():在屏幕上输出所有成员变量的值；
//在测试（Test）类的main()方法中实现创建一个桌子对象，
// 计算桌面的面积，改变桌子重量，并在屏幕上输出所有桌子属性的值。
public class Test {
    public static void main(String[] args) {
        Table table=new Table();
        System.out.println(table.name+"的桌面面积为"+table.area());
        table.weight=6;
        table.display();
    }
}
class Table{
    String name;
    double weight,width,lengeh,height;
    public Table(){
        name = "办公桌";
        weight = 5;
        width = 1.5;
        lengeh =1.7;
        height = 1.2;
    }
    public Table(String name, double weight, double width, double lengeh, double height) {
        this.name = name;
        this.weight = weight;
        this.width = width;
        this.lengeh = lengeh;
        this.height = height;
    }
    double area(){
        return width*lengeh;
    }
    void display(){
        System.out.println("桌子名："+name);
        System.out.println("桌子的重量："+weight);
        System.out.println("桌面宽："+width);
        System.out.println("桌面长："+lengeh);
        System.out.println("桌子高："+height);
    }
}