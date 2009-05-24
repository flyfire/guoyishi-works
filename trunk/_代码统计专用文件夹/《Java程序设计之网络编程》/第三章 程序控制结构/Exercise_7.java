public class Exercise_7 {
	public static void main(String[] args) {
		one:
		for (int i = 0; i < 3; ++i) {
			two:
			for (int j = 10; j < 30; j +=10) {
				System.out.println(i + j);
				if (i > 1)
					continue one;
				System.out.println("One time one print");
			}
			System.out.println("Our 'two'");
		}
		System.out.println("Out 'one'");
	}
}