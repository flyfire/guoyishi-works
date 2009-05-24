//20090429 by Yishi Guo
// 7-3 ParseInt.java
public class ParseInt {
	public static void main(String[] args) {
		String s1 = "12";
		String s2 = "23";
		String s = null;
		int i1 = 0, i2 = 0, sum = 0;
		i1 = Integer.parseInt(s1);
		i2 = new Integer(s2).intValue();
		sum = i1 + i2;
		System.out.println("sum: " + sum);
		s = Integer.toString(sum);
		System.out.println(sum);
	}
}
