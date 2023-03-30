public class Bank {
    private String User;
    private String Name;
    private String  time;
    private int id;
    private double Money;
    Bank(String user,String name,String time,int id,double money){
        this.User=user;
        this.Name=name;
        this.time=time;
        this.id=id;
        this.Money=money;
    }
    void cun(double inMoney){
        this.Money=this.Money+inMoney;
    }
    void qu(double outMoney) {
        this.Money=this.Money-outMoney;
    }
    void info(){
        System.out.println("账户："+User+'\n'+"姓名："+Name+'\n'+"时间："+time+'\n'+"ID："+id+'\n'+"余额："+Money);
    }
}
