//5-11 GroupThree.java
//20090417 by Yishi Guo
public class GroupThree {
	private static int count = 0;
	private String name;
	
	public class Student {
		private int count = 0;
		private String name;
		public void output(int count) {
			count++;
			this.count++;
			GroupThree.count++;
			GroupThree.this.count++;
			System.out.println(count + " " + this.count + " " +
					GroupThree.count + " " + GroupThree.this.count);
		}
	}
	
	public Student returnStu() {
		return new Student();
	}
	
	public static void main(String args[]) {
		GroupThree g3 = new GroupThree();
		g3.count = 10;
		GroupThree.Student s1 = g3.returnStu();
		
		s1.output(5);
	}
	
}