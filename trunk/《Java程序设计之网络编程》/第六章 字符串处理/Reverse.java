//20090425 by Yishi Guo
public class Reverse {
	public static void main(String[] args) {
		String strSource = new String("meiyou.org");
		String strDest = reverseIt(strSource);
		System.out.println("strSource: " + strSource);
		System.out.println("strDest(reversed): " + strDest);
		
	}

	public static String reverseIt(String strSource) {
		StringBuffer sbfSource = new StringBuffer();
		for (int i = strSource.length() - 1; i >= 0; i--) {
			sbfSource.append(strSource.charAt(i));
		}
		return sbfSource.toString();
	}
}
