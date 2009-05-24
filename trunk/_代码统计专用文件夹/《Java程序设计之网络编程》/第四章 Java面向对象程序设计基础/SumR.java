//20090320 Sum Result
import java.io.*;
public class SumR {
	public static int sum(int n) {
		if (n < 1)
			return 0;
		else
			return sum(n - 1) + n;
	}
	
	public static void main(String[] args) {
		int result = 0;
		String str;
		int num = 0;
		System.out.println("Please input the number:");
		try {
			DataInputStream in = new DataInputStream(System.in);
			str = in.readLine();
			num = Integer.parseInt(str);
		}
		catch(Exception e) {
		}
		result = sum(num);
		System.out.println(result);
	}
}	