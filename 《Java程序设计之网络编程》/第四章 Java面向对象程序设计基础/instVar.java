//20090314 4-6 Instance Var
class koA {
	int a;
	public void display() {
		System.out.println("a = " + a);
	}
}

public class instVar {
	public static void main(String[] args) {
		koA val1 = new koA();
		val1.a = 10;
		
		koA val2 = new koA();
		val2.a = 20;
		
		val1.display();
		val2.display();
	}
}