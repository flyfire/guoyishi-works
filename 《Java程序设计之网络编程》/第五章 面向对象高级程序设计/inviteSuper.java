//20090413 5-4 inviteSuper.java
class superClass {
	int y;
	superClass() {
		y = 30;
		System.out.println("in superClass: y = " + y);
	}
	
	void doPrint() {
		System.out.println("In superClass.doPrint()");
	}
}

class subClass extends superClass {
	int y;
	subClass() {
		super();
		y = 50;
		System.out.println("in subClass:y = " + y);
	}
	void doPrint() {
		super.doPrint();
		System.out.println("in subClass.doPrint()");
		System.out.println("super.y = " + super.y + " sub.y = " + y);
	}
}

public class inviteSuper {
	public static void main(String args[]) {
		subClass subSC = new subClass();
		subSC.doPrint();
	}
}
		