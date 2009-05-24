//20090413 5-5 Mokey.java
class Mammal {
	public int n = 40;
	void crySpeak(String s) {
		System.out.println(s);
	}
}

public class Monkey extends Mammal {
	void computer(int v1, int v2) {
		System.out.println(v1 * v2);
	}
	
	void crySpeak(String s) {
		System.out.println("**" + s + "**");
	}
	
	public static void main(String args[]) {
		Mammal mammal = new Monkey();
		mammal.crySpeak("I love this game");
		//mammal.computer(10, 2);
		Monkey monkey = new Monkey();
		mammal = monkey;
		monkey.computer(10, 2);
	}
}