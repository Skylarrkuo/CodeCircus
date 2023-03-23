public class Test {
    public static void main(String args[]) {
        Car car = new Car("五菱宏光", 9999);
        TestCar test = new TestCar();
        test.test(0.9f);
        car.dismessage();
    }
}
