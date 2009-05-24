//6-3 AccesString.java
//20090420 by Yishi Guo
public class AccesString {
	public static void main(String[] args) {
		int n1, n2, n3;
		String ko = "Visual Basic", La = " Java", s1, s2, s3, s4 = "C++";
		s1 = ko.concat(La);
		s2 = s1.substring(4, 10);
		s3 = ko.replace('s', 'x');
		n1 = s1.length();
		n2 = s1.indexOf(La);
		n3 = s1.lastIndexOf("Visual");
		System.out.println(s1);
		System.out.println(s1);
		System.out.println(s3);
		System.out.println(n1);
		System.out.println(n2);
		System.out.println(n3);
	}
}
