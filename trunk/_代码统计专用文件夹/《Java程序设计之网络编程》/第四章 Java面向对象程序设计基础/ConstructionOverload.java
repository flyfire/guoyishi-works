//20090314 4-5 Construction Overload
class Demo {
	int ival1, ival2, ival3;
	
	public Demo() {
	}
	
	public Demo(int a) {
		ival1 = a;
	}
	
	public Demo(int a, int b) {
		ival1 = a;
		ival2 = b;
	}
	
	public Demo(int a, int b, int c) {
		ival1 = a;
		ival2 = b;
		ival3 = c;
	}
	
	void print(int count) {
		System.out.println("·½·¨" + count + ":");
		System.out.println("a = " + ival1 + " b = " + ival2 + " c = " + ival3);
	}
}

public class ConstructionOverload {
	public static void main(String[] args) {
		Demo aDemo = new Demo();
		aDemo.print(1);
		
		Demo bDemo = new Demo(4);
		bDemo.print(2);
		
		Demo cDemo = new Demo(2, 9);
		cDemo.print(3);
		
		Demo dDemo = new Demo(0, 3, 21);
		dDemo.print(4);
	}
}
	
	