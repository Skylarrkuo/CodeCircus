package k11;
public class Student {
    long studentID;
    int classID;
    String Name;
    String Sex;
    int Age;
    Student(long studentID,int classID,String name,String sex,int age){
        this.studentID=studentID;
        this.classID=classID;
        this.Name=name;
        this.Sex=sex;
        this.Age=age;
    }
    long getStudentID() {
        return studentID;
    }
    int getClassID(){
        return classID;
    }
    String getName() {
        return Name;
    }
    String getSex() {
        return Sex;
    }
    int getAge(){
        return Age;
    }
    public String toString(){
       return String.format("%s\n%d\n%s\n%s\n%d", getStudentID(), getClassID(), getName(), getSex(), getAge());
    }
}

