//11-6 TestCardLayout.java by Yishi Guo
//20090605 http://meiyou.org
import java.awt.*;
import java.awt.event.*;
public class TestCardLayout extends WindowAdapter implements ActionListener {
	private Frame frame;
	private CardLayout cardLayout;
	
	public void run() {
		frame = new Frame("Test Card Layout");
		frame.setSize(150, 200);
		frame.addWindowListener(this);
		
		Button button1 = new Button("Card 1");
		Button button2 = new Button("Card 2");
		Button button3 = new Button("Card 3");
		
		Panel panel1 = new Panel();
		Panel panel2 = new Panel();
		Panel panel3 = new Panel();
		
		button1.addActionListener(this);
		panel1.add(button1);
		
		button2.addActionListener(this);
		panel2.add(button2);
		
		button3.addActionListener(this);
		panel3.add(button3);
		
		cardLayout = new CardLayout();
		frame.setLayout(cardLayout);
		
		frame.add(panel1, "First!");
		frame.add(panel2, "Second!");
		frame.add(panel3, "Third!");
		
		frame.setVisible(true);
	}
	
	public void windowClosing(WindowEvent e) {
		System.exit(0);
	}
	
	public void actionPerformed(ActionEvent e) {
		cardLayout.next(frame);
	}
	
	public static void main(String[] args) {
		TestCardLayout myCardLayout = new TestCardLayout();
		myCardLayout.run();
	}
	
}
