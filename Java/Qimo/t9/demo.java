package t9;
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