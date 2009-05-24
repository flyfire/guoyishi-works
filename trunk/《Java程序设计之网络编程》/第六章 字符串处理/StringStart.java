//6-1 StringStart.java
//20090420 by Yishi Guo
public class StringStart {
	public static void main(String[] args) {
		String john = "20040081", start = "2004";
		if ((john.startsWith(start)) && (john.endsWith("1"))) {
			System.out.println("该生是2004级男学生");
		}
		else
			System.out.println("该生不是2004级男学生");
	}
}
