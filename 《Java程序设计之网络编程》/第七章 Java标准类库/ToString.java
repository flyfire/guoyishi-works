//20090429	by Yishi Guo
// 7-4 ToString.java
public class ToString {
	public static void main(String[] args) {
		int i = 345;
		String s = null;
		System.out.println("�������ַ���:" + Integer.toBinaryString(i));
		System.out.println("�˽����ַ���:" + Integer.toOctalString(i));
		System.out.println("ʮ�������ַ���:" + Integer.toHexString(i));
		s = Integer.toString(i, 7);
		System.out.println("������7�����ַ���:" + s);
		Integer I = Integer.valueOf(s, 8);
		System.out.println("Integer�����е�ֵ:" + I.intValue());
	}
}