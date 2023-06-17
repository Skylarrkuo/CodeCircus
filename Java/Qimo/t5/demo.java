package t5;
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