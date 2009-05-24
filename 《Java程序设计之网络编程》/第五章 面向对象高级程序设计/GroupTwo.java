//5-10 GroupTwo.java
//20090417 by Yishi Guo
public class GroupTwo {
	private int count = 0;
	public class Student {
		String name;
		public Student(String str) {
			name = str;
			count++;
		}
		
		public void output() {
			System.out.println(this.name);
		}
	}
	
	public void output() {
		Student s1 = new Student("Yishi Guo");
		s1.output();
		System.out.println("count = " + this.count);
	}
	
	public static void main(String args[]) {
		GroupTwo g2 = new GroupTwo();
		g2.output();
	}
}