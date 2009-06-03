//Error
//11-7 EventTest.java by Yishi Guo
//20090603 http://meiyou.org
import java.awt.*;
import java.awt.event.*;
public class EventTest implements ActionListener, WindowListener {
	Frame f;
	Button b;
	
	public EventTest() {
		f = new Frame("testing");
		b = new Button("press");
		
		b.addActionListener(this);
		f.addWindowListener(this);
		f.add(b, "North");
		f.setSize(200, 200);
		f.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e) {
		b.setLabel(" I have been pressed");
	}
	
	public void windowActivated(WindowEvent e) {};
	public void windowClosed(WindowEvent e) {};
	public void windowClosing(WindowEvent e) {};
	public void windowDeactivated(WindowEvent e) {};
	public void windowDeiconified(WindowEvent e) {};
	public void windowIconfied(WindowEvent e) {};
	public void windowOpened(WindowEvent e) {};
	
	public static void main(String[] args) {
		EventTest et = new EventTest();
	}

}
