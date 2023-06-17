package t8;
//4.假设银行Bank已有了按整年计算利息的一般方法，其中year只能取整数，利率计算规则为：存款数*年数*利率。
//建设银行（ConstructionBank）和中国银行（ChinaBank）都是银行的子类，准备隐藏继承的成员变量year
// 并重写计算利息的方法，即自己声明一个double类型的year变量，比如当year取值为5.216时，表示要计算5年零216天的利息
// 但希望首先按照银行Bank的方法computerInterest()计算出5整年的利息，然后再自己计算216天的利息，
// 那么，建设银行就必须把5.216的整数部分赋给隐藏的year，并让super调用隐藏的，按整年计算利息的方法。
//分别创建ConstructionBank类和ChinaBank类继承Bank类，子类重写父类的computerInterest()方法，
// 创建主类SaveMoney，在主类中创建ConstructionBank和ChinaBank对象，初始化存款数为10000
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