package packone;
public class A {
    public static void main(String[] args) {
        Clock c= new Clock(5,20,10);
        System.out.println("从类A中访问Clock hour"+c.getHour());
        System.out.println("从类A中访问Clock minute"+c.getMinute());
        System.out.println("从类A中访问Clock seconf"+c.getSecond());
    }
}
