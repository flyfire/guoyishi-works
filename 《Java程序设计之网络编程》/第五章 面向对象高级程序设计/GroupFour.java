//5-12 GroupFour.java
//20090417 by Yishi Guo
public class GroupFour {
	public static class Student {
		static int count;
		String name;
		int number;
		public Student(String n1) {
			name = n1;
			count++;
			number = count;
			
		}
		
		public void output() {
			System.out.println(this.name + " number = " + this.number);
		}
	}
	
	public static void main(String args[]) {
		GroupFour.Student s1 = new GroupFour.Student("A");
		s1.output();
		GroupFour.Student s2 = new GroupFour.Student("B");
		s2.output();
	}
}