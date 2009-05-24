//20090420 by Yishi Guo
class IndexOf {
	String str = "I want to go home!";
	public IndexOf(){
		System.out.println("IndexOf");
		System.out.println("str.indexOf(\'t\'):" + str.indexOf('t'));
		System.out.println("str.indexOf(\'o\', 9):" + str.indexOf('o', 9));
		System.out.println("str.indexOf(\"go\"):" + str.indexOf("go"));
	}
}

class LastIndexOf {
	String str = "I want to go home!";
	public LastIndexOf() {
		int var1, var2, var3;
		var1 = str.lastIndexOf('o');
		var2 = str.lastIndexOf('o', 9);
		var3 = str.lastIndexOf("go");
		System.out.println("LastIndexOf:");
		System.out.println("str.lastIndexOf(\'o\'):" + var1);
		System.out.println("str.lastIndexOf(\'o\', 9):" + var2);
		System.out.println("str.lastIndexOf(\"go\"):" + var3);
	}
}
public class TestOfIndexOf {
	public static void main(String[] args) {
		new IndexOf();
		new LastIndexOf();
	}
}
