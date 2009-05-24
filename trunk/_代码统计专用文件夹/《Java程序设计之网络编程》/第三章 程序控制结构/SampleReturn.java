//20090312 Sample Return
public class SampleReturn {
	public static void main(String args[]) {
		boolean flag = true;
		System.out.println("Before the return.");
		if (flag)
			return;
		System.out.println("This won't execute.");
	}
}