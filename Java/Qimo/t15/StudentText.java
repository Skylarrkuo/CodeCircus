package t15;
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
