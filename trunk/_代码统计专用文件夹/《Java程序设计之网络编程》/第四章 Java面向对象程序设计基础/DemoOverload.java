//20090314 4-4 Demo Over Load
class Demo2 {
	int ival1, ival2;
	
	int method() {
		System.out.println("ival1 + ival2 = " + (ival1 + ival2));
		return ival1 + ival2;
	}
	
	int method(int ival3) {
		return ival1 + ival2 + ival3;
	}
	
	int method(int ival3, int ival4) {
		return ival1 + ival2 + ival3 + ival4;
	}
	
	Demo2(int a, int b) {
		ival1 = a;
		ival2 = b;
	}
}
public class DemoOverload {
	public static void main(String[] args) {
		Demo2 Demo = new Demo2(1, 2);
		int a = Demo.method();
		System.out.println(a);
		int b = Demo.method(3);
		System.out.println(b);
		int c = Demo.method(4, 7);
		System.out.println(c);
	}
}	
	