package T2;
public class Student {
    String name;
    double courseA,courseB,courseC;
     public Student(String name, double courseA, double courseB, double courseC) {
        this.name = name;
        this.courseA = courseA;
        this.courseB = courseB;
        this.courseC = courseC;
    }

    public String getName() {
        return name;
    }
    public double getAverage() {
        return (courseA+courseB+courseC)/3;
    }
}
class UnderGraduate extends Student{
    public UnderGraduate(String name, double courseA, double courseB, double courseC) {
        super(name, courseA, courseB, courseC);
    }
    void isPass(){
        System.out.println("本科生"+getName()+"的平均成绩为"+getAverage());
        if(getAverage()>=60){
            System.out.println("可以拿到本科生学位");
        }else{
            System.out.println("可以拿到研究生学位");
        }
    }
}
class Graduate extends Student{
    public Graduate(String name, double courseA, double courseB, double courseC) {
        super(name, courseA, courseB, courseC);
    }
    void isPass(){
        System.out.println("研究生"+getName()+"的平均成绩为"+getAverage());
        if(getAverage()>=80){
            System.out.println("可以拿到研究生学位");
        }else{
            System.out.println("可以拿到研究生学位");
        }
    }
}
