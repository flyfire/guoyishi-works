//20090320 Class And Instance
class SubClass {
}

class SuperClass extends SubClass {
}

public class ClassAndInstance {
	public static void main(String[] args) {
		test(new SubClass());
		test(new SuperClass());
	}
	static void test(Object x) {
		System.out.println("Testing x of type" + x.getClass());
		System.out.println("x instanceof SubClass" + (x instanceof SubClass));
		System.out.println("x instanceof SuperClass" + (x instanceof SuperClass));
	}
}