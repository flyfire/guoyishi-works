//20090420 by Yishi Guo
class Trim {
	public Trim() {
		String str = "  I am Chinese!   ";
		System.out.println("Trim:");
		System.out.println(str + "\n" + str.trim());
	}
}
public class Replace {
	public Replace() {
		String str = "I need Your help!";
		System.out.println("Replace:");
		System.out.println(str.replace('e', 'V'));
		System.out.println(str.replaceAll("Your", "Mine"));
	}
	public static void main(String[] args) {
		new Replace();
		new Trim();
	}
}
