//20090420 by Yishi Guo
public class SubString {
	public SubString() {
		String str = new String("Java is interesting");
		String newStr1 = str.substring(6);
		String newStr2 = str.substring(5, 10);
		System.out.println(newStr1 + "\n" + newStr2);
	}
	public static void main(String[] args) {
		new SubString();
	}
}
