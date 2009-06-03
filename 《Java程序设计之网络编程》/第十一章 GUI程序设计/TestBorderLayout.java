//TestBorderLayout.java by Yishi Guo
//20090603 http://meiyou.org
import java.awt.*;
import java.awt.event.*;
public class TestBorderLayout extends WindowAdapter{
	public TestBorderLayout() {
	}
	
	public void windowClosing(WindowEvent e) {
		System.exit(0);
	}
	
	public static void main(String[] args) {
		Frame frame = new Frame("Test Border Layout");
		frame.setSize(300, 200);
		frame.addWindowListener(new TestBorderLayout());
		
		Button buttonEast = new Button("East");
		Button buttonSouth = new Button("South");
		Button buttonWest = new Button("West");
		Button buttonNorth = new Button("North");
		Button buttonCenter = new Button("Center");
		
		frame.setLayout(new BorderLayout(10, 10));
		frame.add("East", buttonEast);
		frame.add("South", buttonSouth);
		frame.add("West", buttonWest);
		frame.add("North", buttonNorth);
		frame.add("Center", buttonCenter);
		
		frame.setVisible(true);
	}
	
}
