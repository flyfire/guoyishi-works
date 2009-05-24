//20090312 Continue Label 3-10
public class ContinueLabel {
	public static void main(String[] args) {
		outer:
		for (int i = 1; i <= 9; ++i) {
			for (int j = 1; j <= 9; ++j) {
				if (i < j) {
				System.out.println();
					continue outer;
				}
				System.out.print(i * j + " ");
			}
		}
	}
}