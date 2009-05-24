//20090312 Break Loop
public class BreakLoop {
	public static void main(String[] args) {
		for (int i = 0; i < 100; ++i) {
			if (i == 5)
				break;
			System.out.println("i: " + i);
		}
		System.out.println("Loop complete.");
	}
}