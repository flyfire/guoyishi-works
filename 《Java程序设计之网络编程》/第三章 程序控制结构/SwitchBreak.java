//20090312 3-2
public class SwitchBreak {
	public static void main(String args[]) {
		int month = 5;
		String season;
		switch (month) {
			case 12:
			case 1:
			case 2:
				season = "Winter";
				break;
			case 3:
			case 4:
			case 5:
				season = "Spring";
				break;
			case 6:
			case 7:
			case 8:
				season = "Summer";
				break;
			case 9:
			case 10:
			case 11:
				season = "Autumn";
				break;
			default:
				season = "Wrong Number";
		}
		System.out.println("May is in the " + season + ".");
	}
}