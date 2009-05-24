//20090312 3-6 For Each
public class SampleForEach {
	public static void main(String args[]) {
		int sum = 0;
		int a [] = new int[100];
		for (int i = 101; i <= 200; ++i) {
			a[i-101] = i;
		}
		for (int e: a)
			sum = sum + e;
		System.out.println("the sum is " + sum);
	}
}