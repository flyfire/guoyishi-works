//20090302 ��1-3
import javax.swing.*;
public class Proba {
public static void main(String[] args){
	String input =
		JOptionPane.showInputDialog("�û�ϣ����ȡ���ٸ���?");
	int m = Integer.parseInt(input);
	input = JOptionPane.showInputDialog("һ���ж��ٸ���?");
	int n = Integer.parseInt(input);
	int result = 1;
	for (int i = 1; i <= m; ++i) {
		result = result * (n - i + 1) / i;
	}
	System.out.println("�û��н��ļ����� 1/" + result + "");
	System.exit(0);
	}
}