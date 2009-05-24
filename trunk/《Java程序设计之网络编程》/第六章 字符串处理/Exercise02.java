//20090425 by Yishi Guo
public class Exercise02 {
	public static void main(String[] args) {
		String str = "I'm Chinese!";
		char[] chArray = str.toCharArray();
		for (int index = 0; index != chArray.length; index++) {
			char ch = str.charAt(index);
			if (Character.isUpperCase(ch)) {
				chArray[index] = Character.toLowerCase(ch);
			}
			else {
				chArray[index] = Character.toUpperCase(ch);
			}
		}
		String strChanged = String.valueOf(chArray);
		
		System.out.println("str: " + str);
		System.out.println("Changed: " + strChanged);
	}
}
