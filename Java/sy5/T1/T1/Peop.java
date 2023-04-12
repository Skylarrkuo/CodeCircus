package T1;
public class Peop {
    private String name;
    private String sex;
    private int age;
    public Peop(){
        this.name="张三";
        this.age=10;
        this.sex="男";
    }
    public Peop(String name, String sex, int age) {
        this.name = name;
        this.sex = sex;
        this.age = age;
    }

    void showInfo(){
        System.out.println(name);
        System.out.println(sex);
        System.out.println(age);
    }
}
class Student extends Peop{
    String ID;
    Student(){
        super();
        this.ID="666";
    }
    Student(String name, String sex, int age, String ID) {
        super(name, sex, age);
        this.ID = ID;
    }

    void showInfo() {
        super.showInfo();
        System.out.println(ID);
    }
}