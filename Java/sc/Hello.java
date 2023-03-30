public class Hello{
		public static void main(String args[]){
			System.out.println("大家好！");
			System.out.println("Nice to meet you");
			Student stu = new Student();
			stu.speak("We are students");
		}
}
class Student{
	public Student(int i, int j, String string, String string2, int k) {
    }

    public void speak(String s){
		System.out.println(s);
	}
}