import java.util.StringTokenizer;

//20090425
class CountTokens {
	public CountTokens() {
		String str = new String("meiyou.org is my website.");
		StringTokenizer st = new StringTokenizer(str, ",.'");
		int nTokens = st.countTokens();
		System.out.println("str: " + str);
		System.out.println("nTokens: " + nTokens);
	}
}

class TestToken {
	public TestToken() {
		StringTokenizer st = new StringTokenizer("This is a Java programming.");
		while (st.hasMoreTokens()) {
			System.out.println(st.nextElement());
		}
	}
}

class NumberToken {
	public NumberToken() {
		String str = "I am T E A , J X J is my girlfriend?";
		StringTokenizer st = new StringTokenizer(str, " ,?");
		int number = st.countTokens();
		while (st.hasMoreTokens()) {
			String s = st.nextToken();
			System.out.println(s);
			System.out.println("Next: " + st.countTokens());
		}
	}
}
public class TestOfStringTokenizer {
	public static void main(String[] args) {
		new CountTokens();
		new TestToken();
		new NumberToken();
		
	}
}
