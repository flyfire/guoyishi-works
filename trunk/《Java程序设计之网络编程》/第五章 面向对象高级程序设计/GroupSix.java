//5-14 GroupSix.java
//20090417 by Yishi Guo
public class GroupSix {
	public interface Student_info {
		public void output();
	}
	
	public class Student implements Student_info {
		 int count;
		String name;
		public Student(String n1) {
			name = n1;
			count++;
		}
		
		public void output() {
			System.out.println(this.name + " count = " + this.count);
		}
	}
	
	public GroupSix(String name1[]) {
		Student s1;
		int i = 0;
		while (i < name1.length) {
			s1 = new Student(name1[i]);
			s1.output();
			i++;
		}
	}
	
	public static void main(String args[]) {
		String arr[] = {"A", "B", "C"};
		GroupSix g6 = new GroupSix(arr);
	}
}