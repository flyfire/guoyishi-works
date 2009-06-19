//8-1 Exception1.java by Yishi Guo
//20090613 http://meiyou.org
import java.io.*;
public class Exception1 {
	public static void main(String args[]) throws IOException {
		FileInputStream fis = new FileInputStream("text.txt");
		int b;
		while ((b = fis.read()) != -1) {
			System.out.println(b);
		}
		
		fis.close();
	}
}
