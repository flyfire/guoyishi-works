import javax.swing.*;
public class ArrayAvgChanged {
	public static void main(String[] args) {
		final int ARRAY_SIZE = 10;
		int a[] = new int[ARRAY_SIZE];
		int i = 0,j;
		int sum = 0;
		double avg = 0.0;
		String input;
		for (i = 0, j = i +1; i < a.length; ++i, ++j) {
			input = JOptionPane.showInputDialog("请输入第" + j +"个数字 ");
			a[i] = Integer.parseInt(input);
			sum += a[i];
		}
		for (i = 0; i < a.length; ++i) {
			System.out.print(" " + a[i]);
		}
		System.out.println();
		avg = (double)sum/a.length;
		System.out.println("average = " + avg);
	}
}