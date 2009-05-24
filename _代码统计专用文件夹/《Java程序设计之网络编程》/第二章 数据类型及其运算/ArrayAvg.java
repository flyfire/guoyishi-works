public class ArrayAvg {
	public static void main(String[] args) {
		final int ARRAY_SIZE = 10;
		int a[] = new int[ARRAY_SIZE];
		int i = 0;
		int sum = 0;
		double avg = 0.0;
		for (i = 0; i < a.length; ++i) {
			a[i] = (int)(Math.random() * 10);
			sum += a[i];
			System.out.print(" " + a[i]);
		}
		System.out.println();
		avg = (double)sum/a.length;
		System.out.println("average = " + avg);
	}
}