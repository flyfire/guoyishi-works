//20090429	by Yishi Guo
// 7-4 ToString.java
public class ToString {
	public static void main(String[] args) {
		int i = 345;
		String s = null;
		System.out.println("二进制字符串:" + Integer.toBinaryString(i));
		System.out.println("八进制字符串:" + Integer.toOctalString(i));
		System.out.println("十六进制字符串:" + Integer.toHexString(i));
		s = Integer.toString(i, 7);
		System.out.println("带符号7进制字符串:" + s);
		Integer I = Integer.valueOf(s, 8);
		System.out.println("Integer对象中的值:" + I.intValue());
	}
}