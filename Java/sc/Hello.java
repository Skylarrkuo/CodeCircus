import java.util.Scanner;

public class Hello {
	public static void main(String[] args) {
		int num = (int) (Math.random() * 100) + 1;// (1, 100)
		Scanner scanner = new Scanner(System.in);
		int input = scanner.nextInt();
		while (true) {
			if (input == 0) {
				System.out.println("放弃");
				break;
			} else if (input == num) {
				System.out.println("猜对了");
				break;
			} else if (input < num) {
				System.out.println("猜小了");
				input = scanner.nextInt();
			} else if (input > num) {
				System.out.println("猜大了,输入0放弃");
				input = scanner.nextInt();
			}
		}
	}
}
