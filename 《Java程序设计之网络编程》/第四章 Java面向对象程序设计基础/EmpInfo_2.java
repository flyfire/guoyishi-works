//20090314 EmpInfo 2nd
class EmpInfo {
	String name;
	String designation;
	String department;
	
	void print() {
		System.out.println(name + " is " + designation + " at " + department);
	}
}
public class EmpInfo_2 {
	public static void main(String[] args) {
		EmpInfo employee = new EmpInfo();
		employee.name = "Robert Javaman";
		employee.designation = "Manager";
		employee.department = "Coffee Shop";
		employee.print();
	}
}
	