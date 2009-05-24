//20090429 by Yishi Guo
// 7-7 Elapsed.java
public class Elapsed {
	public static void main(String[] args) {
		long start, end, sum = 0;
		System.out.println("Timing a \"for\" loop from 0 to 1,000,000,000");
		start = System.currentTimeMillis();
		for (int i = 0; i < 1000000000; i++) {
			sum = i * i;
			sum = 0;
		}
		end = System.currentTimeMillis();
		System.out.println("Elapsed time: " + (end - start));
	}
}
