//20090302 例1-3
import javax.swing.*;
public class Proba {
public static void main(String[] args){
	String input =
		JOptionPane.showInputDialog("用户希望抽取多少个数?");
	int m = Integer.parseInt(input);
	input = JOptionPane.showInputDialog("一共有多少个数?");
	int n = Integer.parseInt(input);
	int result = 1;
	for (int i = 1; i <= m; ++i) {
		result = result * (n - i + 1) / i;
	}
	System.out.println("用户中奖的几率是 1/" + result + "");
	System.exit(0);
	}
}