//Wrong!

//11-10 MainClass.java by Yishi Guo
//20090605 http://meiyou.org

import java.awt.*;
import java.awt.event.*;

public class MainClass extends Frame implements ActionListener, WindowListener{
	Button button1 = new Button("Button 1");
	Button button2 = new Button("Button 2");
	
	public MainClass() {
		setLayout(new FlowLayout());
		button1.addActionListener(this);
		button2.addActionListener(this);
		
		setSize(200, 200);
		setVisible(true);
		add(button1);
		add(button2);
	}
	
	public void actionPerformed(ActionEvent e) {
		Object source = e.getSource();
		if (source == button1) {
			button1.setLabel("Pressed");
		}
		else if (source == button2) {
			button2.setLabel("Pressed!");
		}
	}
	
	public void windowClosing (WindowEvent e) {
		System.exit(0);
	}
	
	public void windowActivated(WindowEvent e) {};
	public void windowColsed(WindowEvent e) {};
	public void windowDeactivated(WindowEvent e) {};
	public void windowDeiconified(WindowEvent e) {};
	public void windowIconfied(WindowEvent e) {};
	public void windowOpened(WindowEvent e) {};
	
	public static void main(String[] args) {
		InnerClass ic = new InnerClass();
	}
}
