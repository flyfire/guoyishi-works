//20090312 3-7 WeekDay
import java.io.*;
public class Week {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int year, month, day;
		int total = 0, week;
		boolean leap = false;
		int cnt = 1;
		while (cnt <= 20) {
			total = 0;
			week = 0;

		System.out.print("请输入年份: ");
		year = Integer.parseInt(br.readLine());
		System.out.print("请输入月份: ");
		month = Integer.parseInt(br.readLine());
		System.out.print("请输入天数: ");
		day = Integer.parseInt(br.readLine());
		leap = (year % 400 == 0) | (year % 100 != 0) & (year % 4 == 0);
		week = 1;	//19881211 is Sunday
		total = year - 1980 + (year - 1980 + 3) / 4;
		for (int i = 1; i <= month - 1; ++i) {
			switch(i) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					total += 31;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					total += 30;
					break;
				case 2:
					if (leap)
						total += 29;
					else
						total += 28;
					break;
			}
		}
		total += day;
		week = (week + total) % 7;
		System.out.print("date: " + year + "-" + month + "-" + day + " is ");
		switch (week) {
			case 0:
				System.out.print("Sunday");
				break;
			case 1:
				System.out.print("Monday");
				break;
			case 2:
				System.out.print("Tuesday");
				break;
			case 3:
				System.out.print("Wednesday");
				break;
			case 4:
				System.out.print("Thursday");
				break;
			case 5:
				System.out.print("Friday");
				break;
			case 6:
				System.out.print("Saturday");
				break;
			}				
		}
	}
}