public class Exercise_1 {
	public static void main(String[] args) {
		int sum = 0;
		int item = 1;
		for (int i = 1; i <= 10; ++i) {
			item *= i;
			sum += item;
			System.out.println("i = " + i + " item = " + item + " sum = " + sum);
		}
	}
}
		
		