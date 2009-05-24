//5-8 AbstractTest.java
//20090417 by Yishi Guo
abstract class AbstractClass {
	abstract void callMe();
	void metoo() {
		System.out.println("I am in abstract class AbstractClass!");
	}
}

class ImplementAbstract extends AbstractClass {
	void callMe() {
	System.out.println("I am in class ImplementAbstract void callMe!");
	}
}

public class AbstractTest {
	public static void main(String args[]) {
		AbstractClass Test = new ImplementAbstract();
		Test.callMe();
		Test.metoo();
	}
}