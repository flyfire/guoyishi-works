//5-6 Poly.java
//20090417 by Yishi Guo
class person {
	String name = "Johnson";
	int age = 45;
	person() {
		
	}
	person(String name) {
		this.name = name;
	}
	
	person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public void display() {
		System.out.println("Name = " + name + "," + "Age = " + age);
	}
}

public class Poly {
	public static void main(String args[]) {
		person ko1 = new person();
		person ko2 = new person("Mike");
		person ko3 = new person("Willian", 50);
		
		ko1.display();
		ko2.display();
		ko3.display();
	}
}