//20090429 by Yishi Guo
// 7-2 SampleFloat.java
public class SampleFloat {
	public static void main(String[] args) {
		Float fValue = 3.333f;
		Double dValue = 3.333;
		Float F = new Float(fValue);
		Double D = new Double(dValue);
		
		System.out.println(F.toString());
		System.out.println(D.toString());
		
		fValue = F.floatValue();
		dValue = D.doubleValue();
		
		System.out.println(fValue);
		System.out.println(dValue);
		
		System.out.println(D.equals(F));
		System.out.println(D.equals(D));
		System.out.println(D.equals(3.333));
		System.out.println(D.equals(3.333f));
	}
}
