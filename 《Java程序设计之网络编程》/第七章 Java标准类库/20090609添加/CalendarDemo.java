//7-14 ClendarDemo.java by Yishi Guo
//20090609 http://meiyou.org
import java.util.Calendar;
public class CalendarDemo {
	public static  void main(String[] args) {
		Calendar c = Calendar.getInstance();
		c.setFirstDayOfWeek(Calendar.MONDAY);
		display(c);
		c.set(2009, 11, 20);
		c.set(Calendar.HOUR, 10);
		c.set(Calendar.MINUTE, 23);
		c.set(Calendar.SECOND, 33);
		
		System.out.println("更新后时间: ");
		display(c);
		
		c.add(Calendar.DATE, 10);
		c.add(Calendar.HOUR_OF_DAY, 11);
		System.out.println("调整后的时间: ");
		display(c);
	}
	
	static void display(Calendar c) {
		String months[] = { "1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", 
				"10月", "11月", "12月"};
		String days[] = {"星期天", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期七"};
		System.out.print("日期: " );
		System.out.print(c.get(Calendar.YEAR) + "年");
		System.out.print(months[c.get(Calendar.MONTH)]);
		System.out.print(c.get(Calendar.DATE) + "日");
		System.out.println(days[c.get(Calendar.DAY_OF_WEEK) -1]);
		
		System.out.print("时间: ");
		System.out.print(c.get(Calendar.HOUR) + ": ");
		System.out.print(c.get(Calendar.MINUTE) + ": ");
		System.out.println(c.get(Calendar.SECOND));
	}
}
