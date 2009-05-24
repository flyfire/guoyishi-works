//20090312 Continue
public class SampleContinue {
	public static void main(String args[]) {
		for (int i = 1; i <= 100; ++i) {
			System.out.print(i + " ");
			if (i % 10 != 0)
				continue;
			System.out.println();
		}
	}
}