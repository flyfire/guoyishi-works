//20090429 by Yishi Guo
// 7-5 CharDemo.java
public class CharDemo {
	public static void main(String[] args) {
		char a[] = {'a', 's', '?', 'A', ' ', '$', 'û'};
		for (int i = 0; i < a.length; i++) {
			if (Character.isDigit(a[i]))
				System.out.println(a[i] + " is a digit.");
			if (Character.isLetter(a[i]))
				System.out.println(a[i] + " is a letter.");
			if (Character.isWhitespace(a[i]))
				System.out.println(a[i] + " is a whitespace.");
			if (Character.isUpperCase(a[i]))
				System.out.println(a[i] + " is a uppercase.");
			if (Character.isLowerCase(a[i]))
				System.out.println(a[i] + " is a lowercase.");
			if (Character.isJavaIdentifierPart(a[i]))
				System.out.println(a[i] + " may be part of Java Identifier part.");
			if (Character.isJavaIdentifierStart(a[i]))
				System.out.println(a[i] + " may be part of Java Identifier Start.");
			if (Character.isUnicodeIdentifierPart(a[i]))
				System.out.println(a[i] + " may be part of Unicode Identifier Part.");
			if (Character.isUnicodeIdentifierStart(a[i]))
				System.out.println(a[i] + " may be part of Unicode Identifier Start.");
		}
	}
}
