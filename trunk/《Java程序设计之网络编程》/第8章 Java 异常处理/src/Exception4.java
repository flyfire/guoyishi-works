//8-4 Exception4.java by Yishi Guo
//20090613 http://meiyou.org
import java.io.*;
public class Exception4 {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		FileInputStream fis = new FileInputStream("text.txt");
		int b;
		while ((b = fis.read()) != -1) {
			System.out.println(b);
		}
		
		fis.close();
	}
}
