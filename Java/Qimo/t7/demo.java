package t7;
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