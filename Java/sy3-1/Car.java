public class Car {
    String chePai;
    static float price;
    static float pricel;

    Car(String che, float pri) {
        this.chePai = che;
        this.price = pri;
    }

    void dismessage() {
        System.out.println("品牌：" + chePai);
        System.out.println("原价：" + price);
        System.out.println("打折后:" + pricel);
    }
}
class TestCar {
    void test(float d) {
        Car.pricel = Car.price * d;
    }
}