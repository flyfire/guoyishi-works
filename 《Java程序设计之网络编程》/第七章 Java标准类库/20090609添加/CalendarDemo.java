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
		
		System.out.println("���º�ʱ��: ");
		display(c);
		
		c.add(Calendar.DATE, 10);
		c.add(Calendar.HOUR_OF_DAY, 11);
		System.out.println("�������ʱ��: ");
		display(c);
	}
	
	static void display(Calendar c) {
		String months[] = { "1��", "2��", "3��", "4��", "5��", "6��", "7��", "8��", "9��", 
				"10��", "11��", "12��"};
		String days[] = {"������", "����һ", "���ڶ�", "������", "������", "������", "������", "������"};
		System.out.print("����: " );
		System.out.print(c.get(Calendar.YEAR) + "��");
		System.out.print(months[c.get(Calendar.MONTH)]);
		System.out.print(c.get(Calendar.DATE) + "��");
		System.out.println(days[c.get(Calendar.DAY_OF_WEEK) -1]);
		
		System.out.print("ʱ��: ");
		System.out.print(c.get(Calendar.HOUR) + ": ");
		System.out.print(c.get(Calendar.MINUTE) + ": ");
		System.out.println(c.get(Calendar.SECOND));
	}
}
