//20090302 SimpleInput.java
import java.io.*;
public class SimpleInput {
	public static void main(String args[]) throws IOException {
		String s;
		BufferedReader ir =
			new BufferedReader (new InputStreamReader(System.in));
		s = ir.readLine();
		System.out.println("Input value is: " + s);
		double d = Double.parseDouble(s);
		System.out.println("Input value changed after doubled:" + Math.sqrt(d));
	}
}