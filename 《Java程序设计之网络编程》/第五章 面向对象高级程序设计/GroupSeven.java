//5-15 GroupSeven.java
//20090417 by Yishi Guo
interface Destination {
	String readLabel();
}

public class GroupSeven {
	public Destination dest(String str) {
		class GDestination implements Destination {
			private String label;
			private GDestination(String whereTo) {
				label = whereTo;
				System.out.println(readLabel());
			}
			
			public String readLabel() {
				return label;
			}
		}
			
		return new GDestination(str);
	}
	public static void main(String args[]) {
		GroupSeven g7 = new GroupSeven();
		Destination d = g7.dest("Beijing");
	}
}