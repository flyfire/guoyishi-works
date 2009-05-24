//20090425 by Yishi Guo
class ConvertString {
	public ConvertString() {
		int nInt = 10;
		float fFloat = 3.14f;
		double dDouble = 3.1415926;
		Integer obj1 = new Integer(nInt);
		
		Float obj2 = new Float(fFloat);
		
		Double obj3 = new Double(dDouble);
		
		String str1 = obj1.toString();
		String str2 = obj2.toString();
		String str3 = obj3.toString();
		
		System.out.println(str1);
		System.out.println(str2);
		System.out.println(str3);
			
	}
}

class ConvertSimple {
	public ConvertSimple() {
		char[] cArray;
		int nInt;
		float fFloat;
		double dDouble;
		String strString = new String("meiyou.org");
		String strInteger = new String("881211");
		String strFloat = new String("3.14");
		String strDouble = new String("3.1415926");
		
		cArray = strString.toCharArray();
		nInt = Integer.parseInt(strInteger);
		fFloat = Float.parseFloat(strFloat);
		dDouble = Double.parseDouble(strDouble);
		
		System.out.println();
		System.out.println(cArray);
		System.out.println(nInt);
		System.out.println(fFloat);
		System.out.println(dDouble);
	}
}
public class TestOfConvert {
	public static void main(String[] args) {
		new ConvertString();
		new ConvertSimple();
	}
}
