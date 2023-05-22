public class Bank {
    private double money;
    public void income(double in, double out) throws BankException {
        if (in <= 0.0 || out >= 0.0 || in + out <= 0.0) {
            throw new BankException(in, out);
        }
        double netIncome = in + out;
        System.out.printf("本次计算出的纯收入是：%f元\n", netIncome);
        money = money + netIncome;
    }
    public double getMoney()
    {
        return money;
    }
}

class BankException extends Exception {
    String message;
    public BankException(double m, double n) {
        message = "入账资金" + m + "是负数或支出" + n + "是正数，不符合系统要求";
    }
    public String warnMess(){
        return message;
    }
}
