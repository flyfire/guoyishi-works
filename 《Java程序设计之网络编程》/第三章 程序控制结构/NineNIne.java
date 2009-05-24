//20090312 Continue Label
public class NineNine {
	public static void main(String[] args) {
		for (int i = 1; i <= 9; ++i) {
			for (int j = 1; j <= i; ++j) {
				System.out.print(i * j + " ");
			}
			System.out.println();
		}
	}
}