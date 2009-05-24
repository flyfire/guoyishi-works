//20090312 Break Label
public class BreakLabel {
	public static void main(String[] args) {
		boolean flag = true;
		first: {
			second: {
				third: {
					System.out.println("Before the break.");
					if (flag)
						break second;
					System.out.println("This won't execute");
				}
				System.out.println("This won't execute");
			}
			System.out.println("This is after second block.");
		}
	}
}