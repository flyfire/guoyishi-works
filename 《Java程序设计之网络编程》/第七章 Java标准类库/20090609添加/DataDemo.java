//7-13 DataDemo.java by Yishi Guo
//20090609 http://meiyou.org
import java.util.Date;
public class DataDemo {
	public static void main(String[] args) {
		Date d1 = new Date();
		Date d2 = new Date(1140203030304L);
		
		System.out.println(d1);
		System.out.println(d2);
		if (d2.after(d1)) {
			System.out.println("d2 ÍíÓÚ d1");
		}
		
		System.out.println(d2.compareTo(d1));
		
		d2.setTime(d1.getTime());
		System.out.println(d2);
	}
}
