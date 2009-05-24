//20090413 5-1 TestExtend
class Father {
	private int money;
	float weight, height;
	String head;
	String speak(String s) {
		return s;
	}
}

class Son extends Father {
	String hand, foot;
}

public class TestExtend {
	public static void main(String args[]){
		Son boy = new Son();
		boy.weight = 120f; boy.height = 1.8f;
		boy.head = "One Head"; boy.hand = "Two hands";
		boy.foot = "Two feet";
		System.out.println("I'm Son");
		System.out.println("I have: " + boy.hand + ","
		+ boy.foot + "," + boy.head + ",weight: " + boy.weight + ",Height: " + boy.height);
	}
}