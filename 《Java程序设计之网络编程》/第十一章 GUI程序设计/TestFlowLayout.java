//TestFlowLayout.java by Yishi Guo
//20090603 http://meiyou.org
import java.awt.*;
import java.awt.event.*;
public class TestFlowLayout extends WindowAdapter{
	public TestFlowLayout() {
	}
	
	public void windowClosing (WindowEvent e) {
		System.exit(0);
	}
	
	public static void main(String[] args) {
		Frame frame = new Frame("Test Flow Layout");
		frame.setSize(200, 300);
		frame.addWindowListener(new TestFlowLayout());
		
		Button buttonFirst = new Button("First Button");
		Button buttonSecond = new Button("Second Button");
		Button buttonThird = new Button("Third Button");
		Button buttonFourth = new Button("Fourth Button");
		
		frame.setLayout(new FlowLayout(FlowLayout.LEFT));
		frame.add(buttonFirst);
		frame.add(buttonSecond);
		frame.add(buttonThird);
		frame.add(buttonFourth);
		
		frame.setVisible(true);			
	}
}
