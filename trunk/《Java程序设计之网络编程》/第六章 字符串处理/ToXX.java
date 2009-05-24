//20090420 by Yishi Guo
class ToXXCase {
	public ToXXCase() {
		String str = "Nothing is impossible!";
		System.out.println("ToXXCase:");
		System.out.println(str.toUpperCase());
		System.out.println(str.toLowerCase());
	}
}

class ToCharArray {
	public ToCharArray() {
		String str = new String("Java is something I kike!");
		char[] chArray;
		chArray = str.toCharArray();
		System.out.println("ToCharArray:");
		System.out.println(chArray);
	}
}

/*
 * 
class GetChars {
	public GetChars() {
		String str = "What is your name?";
		char[] chDest = "123456789012345";
		str.getChars(5, 10, chDest, 0);
	}
}
*/

class Concat {
	public Concat() {
		String str1 = "012345";
		String str2 = "567789";
		String str3 = str2.concat(str1);
		System.out.println("Concat:");
		System.out.println(str1 + "\n" + str2 + "\n" + str3);
	}
}
public class ToXX {
	public static void main(String[] args) {
		new ToXXCase();
		new ToCharArray();
		//new GetChars();
		new Concat();
	}
}
