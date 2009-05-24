//5-9 MultiInterface.java
//20090417 by Yishi Guo
interface I1 {
	abstract void test(int i);
}

interface I2 {
	abstract void test(String s);
}

public class MultiInterface implements I1, I2 {
	public void test(int i) {
		System.out.println("i = " + i);
	}
	public void test(String s) {
		System.out.println("s = " + s);
	}
	
	public void test(String s, int i) {
		System.out.println(s + " " + i);
	}
	
	public static void main(String args[]) {
		MultiInterface tempTest = new MultiInterface();
		tempTest.test(23);
		tempTest.test("Yishi Guo");
		tempTest.test("My age", 22);
	}
}