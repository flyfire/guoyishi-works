//20090425 by Yishi Guo
import java.io.*;
public class Exercise03 {
	public static void main(String[] args) throws IOException {
		BufferedReader ir =
			new BufferedReader(new InputStreamReader(System.in));
		double sum = 0;
		int count = 0;
		String s;
		System.out.println("Enter numbers:");
		do {
			s = ir.readLine();
			sum += Double.parseDouble(s);
			count++;
		}while(true);
	}
}
