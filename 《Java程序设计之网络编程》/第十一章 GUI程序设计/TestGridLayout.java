//TestGridLayout.java by Yishi Guo
//20090603 http://meiyou.org
import java.awt.*;
import java.awt.event.*;
public class TestGridLayout extends WindowAdapter {
	public TestGridLayout(){
	}
	
	public void windowClosing(WindowEvent e) {
		System.exit(0);
	}

	public static void main(String[] args) {
		Frame frame = new Frame("Test Grid Layout");
		frame.setSize(200, 300);
		frame.addWindowListener(new TestGridLayout());
		
		Button button1 = new Button("1");
		Button button2 = new Button("2");
		Button button3 = new Button("3");
		Button button4 = new Button("4");
		Button button5 = new Button("5");
		
		frame.setLayout(new GridLayout(2, 2, 10, 10));
		frame.add(button1);
		frame.add(button2);
		frame.add(button3);
		frame.add(button4);
		frame.add(button5);
		
		frame.setVisible(true);
	}
}
