### 1、1!+2!+…+10!的值



```java
//1.编写一个Java程序，求1!+2!+…+10!的值，程序文件命名为“FactoriesSum.java”。
public class FactoriesSum {
    public static void main(String[] args) {
        int sum=0;
        for(int i=1,a=1;i<=10;i++,a=1){
            for(int j=1;j<=i;j++){
                a*=j;
            }
            sum+=a;
        }
        System.out.println("1!+2!+…+10!="+sum);
    }
}
```



### 2、 输出从100-200 之间（包括100和200）的所有质数



```java
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
```



### 3 求100-999之间的水仙花数



```java
//3.编写一个Java程序，求100-999之间的水仙花数，程序文件命名为“Narcissus.java”。
// 提示：水仙花数为一个数的每一位数字的立方之和等于这个数，如数字153，1^3+5^3+3^3=153，以空格分隔输出这些数字。
public class Narcissus {
    public static void main(String[] args) {
        for(int i=100;i<=999;i++){
            int a=i%10;
            int b=i/10%10;
            int c=i/100;
            if(Math.pow(a,3)+Math.pow(b,3)+Math.pow(c,3)==i)
                System.out.printf("%d ",i);
        }
    }
}
```



### 4 、输出1949年-2023年内的闰年



```java
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
```

### 5、“动物”类



```java
//1.编写Java程序实现如下功能
//（1）设计一个“动物”类：Animal，包括：
//①两个公有属性：name（字符串类型）和age（整形）；
//②两个公有方法：eat（void类型，方法参数为：一个字符串类型）和move（void类型，方法参数为空），方法内部各自打印一行语句。
//（2）接下来设计“猫”类：Cat，继承“Animal”类，新增一个公有属性：color（字符串类型）。
//在“猫”类请实现以下方法：
//①构造方法：参数列表为：name、age、color，通过构造方法可以设置猫的这三个属性。
//②公有方法catchAnimal (void类型，方法参数为：一个Animal类型)，方法内部打印：[猫的名字]捉住了[动物的名字]。例如：小花猫捉住了老鼠。
public class demo {
    public static void main(String[] args) {
        Animal mouse=new Animal("老鼠",999);
        Cat cat =new Cat("汤姆猫",3,"蓝色");
        cat.catchAnimal(mouse);
    }
}
  class Animal{
    public String name;
    public int age;
    public Animal(String name1, int age1) {
        this.name = name1;
        this.age = age1;
    }
    void eat(String s){
        System.out.println(s);
    }
    void move(){
        System.out.println("呼..呼..");
    }
}
class Cat extends Animal{
    public String color;
    public Cat(String name, int age,String color) {
        super(name, age);
        this.color=color;
    }
    public void catchAnimal(Animal A){
        System.out.println(this.name+"捉住了"+A.name);
    }
}
```



### 6、形状的抽象类



```java
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
```



### 7 、声音模拟器



```java
import java.lang.*;
//3.编写Java程序，完成如下功能：
//设计一个声音模拟器，希望模拟器可以模拟出喜多动物的叫声，要求如下：
//编写接口Animal。Animal接口有两个抽象方法cry()和getAnimalName()，即要求，实现该接口的各种具体动物类给出自己的叫声和种类名称。
//设计一个动物声音模拟器,希望模拟器可以模拟许多动物的叫声,要求如下:
//(1)编写接口Animal。Animal接口有两个抽象方法cry()和 getAnimalName(),即要求实现该接口的各种具体动物类给出自己的叫声和种类名称。
//(2)编写模拟器类Simulator。该类有一个 playSound(Animal animal)方法,该方法的参数是 Animal类型,
// 即参数animal可以调用实现Animal接口类重写的cry()方法播放具体动物的声音,调用重写的getAnimalName()方法显示动物种类的名称。
//(3)编写实现Animal接口的 Dog类和Cat类。
public class demo {
    public static void main(String[] args) {
        Cat mao=new Cat();
        Dog dog=new Dog();
        Simulator s=new Simulator();
        s.playSound(mao);
        s.playSound(dog);
    }
}
interface Animal{
    public abstract void cry();
    public abstract String getAnimalName();
}
class Simulator{
    void playSound(Animal animal){
        System.out.printf(animal.getAnimalName()+"的叫声是");
        animal.cry();
    }
}
class Dog implements Animal{

    public void cry() {
        System.out.println("汪汪！");
    }

    public String getAnimalName() {
        return (String)"狗";
    }
}
class Cat implements Animal{

    public void cry() {
        System.out.println("喵呜~");
    }

    public String getAnimalName() {
        return (String)"猫";
    }
}
```



### 8、银行Bank



```java
//4.假设银行Bank已有了按整年计算利息的一般方法，其中year只能取整数，利率计算规则为：存款数*年数*利率。
//建设银行（ConstructionBank）和中国银行（ChinaBank）都是银行的子类，准备隐藏继承的成员变量year
// 并重写计算利息的方法，即自己声明一个double类型的year变量，比如当year取值为5.216时，表示要计算5年零216天的利息
// 但希望首先按照银行Bank的方法computerInterest()计算出5整年的利息，然后再自己计算216天的利息，
// 那么，建设银行就必须把5.216的整数部分赋给隐藏的year，并让super调用隐藏的，按整年计算利息的方法。
//分别创建ConstructionBank类和ChinaBank类继承Bank类，子类重写父类的computerInterest()方法，
// 创建主类SaveMoney，在主类中创建ConstructionBank和ChinaBa=nk对象，初始化存款数为10000
// 存款时间为3.216年（3年零216天）、建设银行年利率为2.8%，日利率为0.002%，
// 中国银行年利率为2.9%，日利率为0.0015%，输出两家银行的利息，输出格式为：
//%d元存在建设银行%d年零%d天的利息为%f元\n
//%d元存在中国银行%d年零%d天的利息为%f元\n
//如：
//10000元存在建设银行3年零216天的利息为883.2元
//10000元存在中国银行3年零216天的利息为902.4元
public class SaveMoney {
    public static void main(String[] args) {
        ConstructionBank JS = new ConstructionBank(10000,3.216,0.028,0.00002);
        ChinaBank ZH = new ChinaBank(10000,3.216,0.029,0.000015);
        System.out.printf("%d元存在建设银行%d年零%d天的利息为%f元\n",JS.saveMoney,(int)Math.floor(JS.year),(int)(1000*(JS.year-Math.floor(JS.year))),JS.computerInterest());
        System.out.printf("%d元存在中国银行%d年零%d天的利息为%f元\n",ZH.saveMoney,(int)Math.floor(ZH.year),(int)(1000*(ZH.year-Math.floor(ZH.year))),ZH.computerInterest());
    }
}
class Bank{
    int saveMoney;
    int year;
    double Interest;
    double InterestRate;
    double ComputerInterest(){
        return saveMoney*year*Interest;
    }
    void SetInterestRate(double interest) {
        this.Interest=interest;
    }
}
class ConstructionBank extends Bank{
    double year;
    public ConstructionBank(int saveMoney,double year,double interest, double interestRate) {
        this.saveMoney=saveMoney;
        this.Interest=interest;
        this.InterestRate=interestRate;
        this.year = year;
    }
    double computerInterest(){
        super.year=(int)Math.floor(year);
        return super.ComputerInterest()+saveMoney*1000*(year-Math.floor(year))*InterestRate;
    }
}
class ChinaBank extends Bank{
    double year;
    public ChinaBank(int saveMoney, double year, double interest, double interestRate) {
        this.saveMoney=saveMoney;
        this.Interest=interest;
        this.InterestRate=interestRate;
        this.year = year;
    }
    double computerInterest(){
        super.year=(int)Math.floor(year);
        return super.ComputerInterest()+saveMoney*1000*(year-Math.floor(year))*InterestRate;
    }
}
```

### 9、公司的雇员

```java
//1. 某公司的雇员分为以下若干类：
//(1) Employee：这是所有员工总的父类。
//① 属性：员工的姓名,员工的生日月份
//② 方法：getSalary(int month) 根据参数月份来确定工资，如果该月员工过生日，则公司会额外奖励100 元。
//(2) SalariedEmployee：Employee 的子类，拿固定工资的员工。
//① 属性：月薪。
//(3)HourlyEmployee：Employee 的子类，按小时拿工资的员工，每月工作超出160小时的部分按照1.5 倍工资发放。
//① 属性：每小时的工资、每月工作的小时数。
//(4) SalesEmployee：Employee 的子类，销售，工资由月销售额和提成率决定。
//① 属性：月销售额、提成率。
//(5) BasePlusSalesEmployee：SalesEmployee 的子类，有固定底薪的销售人员，工资由底薪加上销售提成部分。
//① 属性：底薪、提成。
//要求：
//创建一个Employee 数组，分别创建若干不同的Employee对象放入Employee 数组中，初始化
// 张三为SalariedEmployee类型员工月薪为4000元，生日为5月份；
// 李四为HourlyEmployee类型员工，生日为6月份，每小时工资25元，当月工作了200小时；
// 王五为SalesEmployee类型员工，生日为7月份，底薪为2500，提成为3000，当前要发的是6月份工资，要求打印结果为：
//张三6月份的工资为4000元
//李四6月份的工资为5600元
//王五6月份的工资为5500元。
public class demo {
    public static void main(String[] args) {
        Employee[] employees=new Employee[3];
        employees[0]=new SalariedEmployee("张三",5,4000);
        employees[1]=new HourlyEmployee("李四",6,25,200);
        employees[2]=new BasePlusSalesEmployee("王五",7,2500,3000);
        for(int i=0;i<3;i++){
            System.out.printf("%s6月份的工资为%.0f元\n",employees[i].name,employees[i].getSalary(6));
        }
    }
}
abstract class Employee{
    String name;
    int birth;
    public abstract double getSalary(int month);
}
class SalariedEmployee extends Employee{
    double Monthly;
    public SalariedEmployee(String name,int birth,double monthly) {
        this.name=name;
        this.birth=birth;
        Monthly = monthly;
    }
    public double getSalary(int month) {
        if (month==birth)
            return Monthly+100;
        else
            return Monthly;
    }
}
class HourlyEmployee extends Employee {
    double Hourly,hour;
    public HourlyEmployee(String name,int birth,double hourly, double hour) {
        this.name=name;
        this.birth=birth;
        Hourly = hourly;
        this.hour = hour;
    }
    public double getSalary(int month) {
        if(hour<=160){
            if(month==birth)
                return hour*Hourly+100;
            else return hour*Hourly;
        }
        else{
            if(month==birth)
                return (hour-160)*1.5*Hourly+160*Hourly+100;
            else
                return (hour-160)*1.5*Hourly+160*Hourly;
        }
    }
}
class SalesEmployee extends Employee{
    double MonthlySales,RoyaltyRate;
    public double getSalary(int month) {
        return MonthlySales*RoyaltyRate;
    }
}
class BasePlusSalesEmployee extends SalesEmployee{
    double Monthly,Commission;
    public BasePlusSalesEmployee(String name,int birth,double monthly,double commission) {
        this.name=name;
        this.birth=birth;
        Monthly=monthly;
        Commission=commission;
    }
    public double getSalary(int month) {
        if (month==birth)
            return Monthly+Commission+100;
        else
            return Monthly+Commission;
    }
}
```



### 10、控制台输入一个字符串s，请你反转字符串中单词的顺序



```java
import java.util.Scanner;
public class  ReverseStr {
    public static void main(String[] args) {
        String s;
        String regex = "\s+";
        String[] a;
        Scanner read=new Scanner(System.in);
        s=read.nextLine();
        a=s.split(regex);
        for(int i=a.length-1;i>=0;i--){
            System.out.printf("%s ",a[i]);
        }
    }
}
```



### 11、产生10个1-100之间的随机整数输出



```java
import java.util.*;
//1. 产生10个1-100之间的随机整数输出，
// 并把这10个数按从小到大的顺序输出，程序文件命名为“RandomSort.java”。
public class RandomSort {
    public static void main(String[] args) {
        Random random = new Random();
        int[] a = new int[10];
        for(int i=0;i<10;i++){
            a[i]= random.nextInt(90)+10;
        }
        Arrays.sort(a);
        for(int i=0;i<10;i++){
            System.out.printf("%d ",a[i]);
        }
    }
}
```



### 12、使用for循环语句计算5+55+555+5555+..



```java
//2. 编写应用程序，使用for循环语句
// 计算5+55+555+5555+...的前10项之和,程序文件命名为“SequenceSum.java”。
public class SequenceSum {
    public static void main(String[] args) {
        long sum=0;
        for(int i=1;i<=10;i++){
            sum+=(long)((5.0/9.0)*Math.pow(10,i));
        }
        System.out.println("5+55+555+5555+...的前10项之和为"+sum);
    }
}
```



### 13、输出满足1+2+3+...+n>10000



```java
//3. 编写程序，输出
// 满足1+2+3+...+n>10000的最小正整数n,程序文件命名为“IntegerMin.java”。
public class IntegerMin {
    public static void main(String[] args) {
        int sum=0;
        int i=0;
        while (sum<10000){
            sum+=++i;
        }
        System.out.println(i);
    }
}
```



### 14、创建一个桌子（Table）类



```java
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
```



### 15、假定根据学生的3门学位课程的分数决定其是否可以拿到学位



```java
//编写程序，实现以下功能：
//假定根据学生的3门学位课程的分数决定其是否可以拿到学位，
// 对于本科生，如果3门课程的平均分数超过60分即表示通过，
// 而对于研究生，则需要平均超过80分才能够通过。根据上述要求，
// 请完成以下Java类的设计：
//（1）设计一个基类Student描述学生的共同特征。
//（2）设计一个描述本科生的类Undergraduate，该类继承并扩展Student类。
//（3）设计一个描述研究生的类Graduate，该类继承并扩展Student类。
//（4）设计一个测试类StudentText，分别创建本科生和研究生这两个类的对象，
// 并输出相关信息(对应学生的姓名、平均分、是否可以拿到学位)，要求平均分保留2位小数。
public class StudentText {
    public static void main(String[] args) {
        UnderGraduate A =new UnderGraduate("小明",99,80,55);
        Graduate B =new Graduate("李华",60,99,86);
        System.out.printf("本科生%s的平均分为%.2f,他",A.name,A.getAverage());
        A.isPass();
        System.out.printf("研究生%s的平均分为%.2f,他",B.name,B.getAverage());
        B.isPass();
    }
}
class Student{
    String name;
    double courseA,courseB,courseC;
    public Student(String name, double courseA, double courseB, double courseC) {
        this.name = name;
        this.courseA = courseA;
        this.courseB = courseB;
        this.courseC = courseC;
    }
    public String getName(){
        return name;
    }
    public double getAverage(){
        return (courseA+courseB+courseC) /3;
    }
}

class UnderGraduate extends Student{
    public UnderGraduate(String name, double courseA, double courseB, double courseC) {
        super(name, courseA, courseB, courseC);
    }
    void isPass(){
        if(this.getAverage()>=60)
            System.out.print("可以拿到学位\n");
        else
            System.out.print("不可以拿到学位\n");
    }
}
class Graduate extends Student{
    public Graduate(String name, double courseA, double courseB, double courseC) {
        super(name, courseA, courseB, courseC);
    }
    void isPass(){
        if(this.getAverage()>=80)
            System.out.print("可以拿到学位\n");
        else
            System.out.print("不可以拿到学位\n");
    }
}
```



### 16、设计一个计算柱体应用程序，希望该应用程序可以计算不同柱体的体积



```java
//6.编写程序，实现以下功能：
//设计一个计算柱体应用程序，希望该应用程序可以计算不同柱体的体积，要求如下：
//(1)  首先设计一个抽象类Geometry（几何图形）类，
// 在该抽象类中定义一个抽象getArea()方法.
//(2)  然后设计PillarL（柱体）类，
// 该类的对象调用getVolume()方法计算柱体的体积，
//(3)  分别设计Circle（圆）类和Rectangle（矩形）类
// 和Triangle（三角形）类作为Geometry类的子类。
//(4)  最后设计Application测试类分别求出圆柱的体积，
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
```



### 17、设计一个应用程序，该应用程序用接口实现计算三个数的算术平均数和几何平均数



```java
//7.编写程序，实现以下功能：
//设计一个应用程序，该应用程序用接口实现计算三个数的算术平均数和几何平均数，
// 例如有两个数a,b,c其算术平均数为：（a+b+c）/3;
// 其几何平均数为：\sqrt[3]{a\ast b\ast c}。要求如下：
// 设计一个接口（CompurerAverage），该接口有一个抽象方法average（）
// 要求实现该接口的类完成平均数的计算。
// 设计一个ArithmeticAverage类实现算术平均数的运算。
// 设计一个GeometryAverage类实现几何平均数的运算。
// 设计一个TestAverage测试类完成测试。
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
}   }
}
```



### 18、使用Scanner类的实例解析字符串



```java
import java.util.*;
//8. 编写程序，实现以下功能：
//使用Scanner类的实例解析字符串
// “欢迎光临美好生活超市,你所买的苹果20.5元，梨20元,铅笔5.8元，香蕉30.5元，矿泉水20.8元。”
// 中的金额，并计算出此次在超市中花费的总额。要求如下：
//（1）设计一个givePriceSum类用于解析字符串中的金额。
//（2）设计一个PriceSumTest测试类测试结果。
public class PriceSumTest {
    public static void main(String[] args) {
        String cost = "欢迎光临美好生活超市,你所买的苹果20.5元，梨20元,铅笔5.8元，香蕉30.5元，矿泉水20.8元。";
        double priceSum = GetPrice.givePriceSum(cost);
        System.out.printf("%s\n你此次花费的金额为:%.2f元\n",cost,priceSum);
    }
}
class GetPrice {
    public static double givePriceSum(String cost) {
        Scanner scanner = new Scanner(cost);
        scanner.useDelimiter("[^0-9.]+"); //scanner设置分隔标记
        double sum=0;
        while(scanner.hasNext()){
            try{  double price = scanner.nextDouble();
                sum = sum+price;
            }
            catch(InputMismatchException exp){
                String t = scanner.next();
            }
        }
        return sum;
    }
}
```



### 19、使用文件字符输入和输出流将文件source File中的内容加到文件target File中



```java
public class Test {
    public static void main(String args[]) {
      File sourceFile = new File("D:\\myjavafile\\myProject\\myfile\\a.txt");  //读取的文件
      File targetFile = new File("D:\\myjavafile\\myProject\\myfile\\b.txt");  //写入的文件
      char c[] =new char[19];               //char型数组 
      try{  
         Writer out = new FileWriter(targetFile,true); //指向目的地的输出流
         Reader in  = new FileReader(sourceFile);   //指向源的输入流  
         int n = -1;
         while((n=in.read(c))!=-1) {
             out.write(c,0,n);
         }
         out.flush();
         out.close();
      }
      catch(IOException e) {
          System.out.println("Error "+e);
      }
  }
}
```



### 20、输入一行字符串，分别统计出其中英文字母、空格、数



```java
import java.util.*;
//编程实现输入一行字符串，分别统计出其中
// 英文字母、空格、数字和其它字符的个数。程序文件命名为“Counter.java”。
public class Counter {
    public static void main(String[] args) {
        int zm=0,kg=0,sz=0,qt=0;
        Scanner read=new Scanner(System.in);
        String s = read.nextLine();
        char[] a =s.toCharArray();
        for(int i=0;i<a.length;i++){
            if ((a[i]>='a'&&a[i]<='z')||(a[i]>='A' && a[i]<='Z'))    zm++;
            else if (a[i]>='0' && a[i]<='9')   sz++;
            else if (a[i]==' ')  kg++;
            else  qt++;
        }
        System.out.println("字符串["+s+"]中");
        System.out.println("字母有"+zm+"个");
        System.out.println("数字有"+sz+"个");
        System.out.println("空格有"+kg+"个");
        System.out.println("其他字符有"+qt+"个");
    }
}
```