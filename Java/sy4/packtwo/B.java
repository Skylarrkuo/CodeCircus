package packtwo;
import packone.Clock;
class B {
    public static void main(String[] args) {
        packone.Clock c= new packone.Clock(8,30,5);
        System.out.println("从类B中访问Clock hour"+c.getHour());
        System.out.println("从类B中访问Clock minute"+c.getMinute());
        System.out.println("从类B中访问Clock second"+c.getSecond());
    }
}
