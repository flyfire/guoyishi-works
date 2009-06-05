//11-9 InnerClass.java by Yishi Guo
//20090605 http://meiyou.org

import java.awt.*;
import java.awt.event.*;

public class InnerClass extends Frame{
	Button button1 = new Button("Button 1");
	Button button2 = new Button("Button 2");
	
	public InnerClass() {
		setLayout(new FlowLayout());
		button1.addActionListener(new Button1Listener());
		button2.addActionListener(new Button2Listener());
		
		add(button1);
		add(button2);
		
		setSize(200, 200);
		setVisible(true);
		
		addWindowListener(new WindowAdapter() {
			public void WindowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
	}
	
	public class Button1Listener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			button1.setLabel(" Pressed");
		}
	}
	
	public class Button2Listener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			button2.setLabel(" Pressed!");
		}
	}
	
	public static void main(String[] args) {
		new InnerClass();
	}
}