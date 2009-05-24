public class TwoArrayAvg {
	public static void main(String[] args) {
		final int ONE_SIZE = 4;
		final int TWO_SIZE = 5;
		int two[][] = new int[ONE_SIZE][TWO_SIZE];
		int i = 0, j = 0;
		int sum = 0;
		double avg = 0.0;
		for (i = 0; i<4; i++) {
			for (j = 0; i<5; j++) {
				sum += i * j;
				System.out.print(" " + i + j);
			}
			System.out.println();
		}
		avg = (double)sum / (two.length * two[0].length);
		System.out.println("Average = " + avg);
	}
}