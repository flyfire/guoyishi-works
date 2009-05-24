//20090420
class Equals {
	String tom = new String("we are students");
	String boy = new String("We are students");
	String jerry = new String("we are students");
	public Equals() {
		System.out.println("Equals: ");
		System.out.println("tom.equals(boy) = " + tom.equals(boy));
		System.out.println("tom.equals(jerry) = "+ tom.equals(jerry));
	}
}

class EqualsIgnoreCase {
	String tom = new String("we are students");
	String boy = new String("We are students");
	public EqualsIgnoreCase() {
		System.out.println("EqualsIgnoreCase:");
		System.out.println("tom.equalsIgnoreCase(boy) = " + tom.equalsIgnoreCase(boy));
		
	}
}

class StartsWith {
	String test1 = new String("13578916371");
	String test2 = new String("13058219988");
	public StartsWith() {
		System.out.println("StartsWith:");
		System.out.println("test1.startsWith(\"135\") :" + test1.startsWith("135"));
		System.out.println("test2.startsWith(\"135\") :" + test2.startsWith("135"));
		
	}
}

class EndsWith {
	String test3 = new String("123443321");
	String test4 = new String("121112");
	public EndsWith() {
		System.out.println("EndsWith:");
		System.out.println("test3.endsWith(\"12\") :" + test3.endsWith("12"));
		System.out.println("test4.endsWith(\"12\") :" + test4.endsWith("12"));
	}
}

class RegionMatches {
	String test5 = new String("1234567890");
	String test6 = new String("345");
	public RegionMatches() {
		System.out.println("Regionmatches:");
		System.out.println("test5.regionmatches(2, test6, 0, 2):" + test5.regionMatches(2, test6, 0, 2));
	}
}

class CompareTo {
	String str = "abcde";
	public CompareTo() {
		System.out.println("CompareTo:");
		System.out.println("str.compareTo(\"boy\"):" + str.compareTo("boy"));
		System.out.println("str.compareTo(\"toy\"):" + str.compareTo("toy"));
		System.out.println("str.compareTo(\"aba\"):" + str.compareTo("aba"));
		System.out.println("str.compareTo(\"abcde\"):" + str.compareTo("abcde"));
		System.out.println("str.compareToIngnoreCase(\"ABCde\"):" + str.compareToIgnoreCase("ABCde"));
	}
}
public class Testofcontent {
	public static void main(String[] args) {
		String s = "we are students", tom = "我们是学生";
		int n1, n2, n3;
		n1 = s.length();
		n2 = tom.length();
		n3 = "我的爱好".length();
		System.out.println("n1 = " + n1 + "\nn2 = " + n2 + "\nn3 = " + n3);
		
		
		new Equals();
		new EqualsIgnoreCase();
		new StartsWith();
		new EndsWith();
		new RegionMatches();
		new CompareTo();
	}

}