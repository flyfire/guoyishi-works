//FrameWithPanel.java by Yishi Guo
//20090603 http://meiyou.org
import java.awt.*;
public class FrameWithPanel extends Frame{
	public FrameWithPanel(String a) {
		super(a);
	}
	public static void main(String[] args) {
		FrameWithPanel f = new FrameWithPanel("Frame With Panel");
		Panel pan = new Panel();
		f.setSize(200, 200);
		f.setBackground(Color.red);
		f.setLayout(null);
		pan.setSize(100, 100);
		pan.setBackground(Color.yellow);
		f.add(pan);
		f.setVisible(true);
	}
}
