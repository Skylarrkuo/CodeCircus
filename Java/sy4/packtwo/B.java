package packtwo;
import packone.Clock;
class B {
    public static void main(String[] args) {
        Clock c= new packone.Clock(8,30,5);
        System.out.println("从类B中访问Clock hour"+c.hour);
        System.out.println("从类B中访问Clock minute"+c.minute);
        System.out.println("从类B中访问Clock second"+c.second);
    }
}
