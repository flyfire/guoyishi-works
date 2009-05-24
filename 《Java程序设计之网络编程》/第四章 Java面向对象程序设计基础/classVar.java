//20090314 4-7 Class Var
class koB {
	static int a;
	public void display() {
		System.out.println ("a = " + a);
	}
}

public class classVar {
	public static void main(String[] args) {
		koB val1 = new koB();
		val1.a = 10;
		koB val2 = new koB();
		val2.a = 23;
		
		val1.display();
		val2.display();
		
		koB.a = 435;
		
		val1.display();
		val2.display();
	}
}