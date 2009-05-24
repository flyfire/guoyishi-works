//20090320 DemoPrivate.java
public class DemoPrivate {
	public int a;
	private int b;
	
	public int getA() {
		return a;
	}
	
	public int getB() {
		return b;
	}
	
	public DemoPrivate(int ival1, int ival2) {
		a = ival1;
		b = ival2;
	}
	
	public static void main(String[] args) {
		DemoPrivate aDemoPrivate = new DemoPrivate(1, 2);
		int a = aDemoPrivate.getA();
		System.out.println("变量a的值:" + a);
		int b = aDemoPrivate.getB();
		System.out.println("变量b的值:" + b);
	}
}