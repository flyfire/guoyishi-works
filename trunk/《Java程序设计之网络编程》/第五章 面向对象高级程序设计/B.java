//20090413 5-3 B.java
class A {
	public int n;
	public A() {
		n = 0;
	}
	
	public A(int n) {
		this.n = n;
	}
	
	int getValue() {
		return n;
	}
}

public class B extends A {
	public B() {
		super(15);
	}
	
	public B(int n) {
		super(n);
	}
	
	public static void main(String args[]) {
		A aClassValue = new B();
		//OR: A aClassValue = new B(12);
		int b = aClassValue.getValue();
		System.out.println("A: " + b);
	}
}