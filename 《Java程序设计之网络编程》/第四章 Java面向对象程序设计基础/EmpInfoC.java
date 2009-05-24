//20090314 4-3 Employee Information
public class EmpInfoC {
	String name;
	String designation;
	String department;
	
	public EmpInfoC(String nam, String des, String dep) {
		name = nam;
		designation = des;
		department = dep;
	}
	
	void print() {
		System.out.println(name + " is " + designation + " at " + department);
	}
	
	public static void main(String[] args) {
		EmpInfoC employee =
		new EmpInfoC("Robert Javaman", "Manager", "Coffee Shop");
		
		employee.print();
	}
}