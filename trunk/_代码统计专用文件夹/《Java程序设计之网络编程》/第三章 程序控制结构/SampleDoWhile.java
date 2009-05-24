//20090312 3-4 do-while
public class SampleDoWhile {
	public static void main(String[] args) {
		int sum = 0, i = 100;
		do {
			++i;
			sum += i;
		} while(i < 200);
		System.out.println("the sum is " + sum);
	}
}