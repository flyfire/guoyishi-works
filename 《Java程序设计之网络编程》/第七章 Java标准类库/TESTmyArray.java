//20090515 by Yishi Guo
// test MyArray class
public class TESTmyArray {
	public static void main(String[] args) {
		MyArray ma = new MyArray();
		int i = 0;
		System.out.println("FIRST TIME:");
		while (i++ != 30) {
			ma.add((Integer)i);
			System.out.println(i);
		}
		
		//Test print
		System.out.println("\nSECOND TIME:");
		i = 0;
		while (i != ma.size()) {
			System.out.println(ma.get(i));
			i++;
		}
		
		//test remove
		System.out.println("\nTHIRD TIME:");
		i = 2;
		while (i < ma.size()) {
			ma.remove(i);
			i += 2;
		}
		//remove 0
		ma.remove(0);
		//remove size
		ma.remove(ma.size());
		i = 0;
		while (i != ma.size()) {
			System.out.println(ma.get(i));
			i++;
		}
		
		//test insert
		System.out.println("\n4 TIME:");
		MyArray ma2 = new MyArray();
		i = 0;
		while (i++ != 10) {
			ma2.add((Integer)(i*10));
		}
		ma2.insert(2, (Integer)(1234));
		i = 0;
		while (i < ma2.size()) {
			System.out.println(ma2.get(i));
			i++;
		}
		
		//test clear
		System.out.println("\n5 :");
		ma2.clear();
		i = 0;
		System.out.println("size: " + ma2.size());
		while (i < ma2.size()) {
			System.out.println("\n" + ma2.get(i) + " size: " + ma2.size() );
			i++;
		}
		
		//test insert again
		i = 0;
		while (i++ != 10) {
			ma2.add((Integer)(i*10));
		}
		ma2.insert(2, (Integer)(1234));
		ma2.insert(0, (Integer)(18234));
		ma2.insert(10, (Integer)(10234));
		
		System.out.println("\n6 :");
		i = 0;
		while (i < ma2.size()) {
			System.out.println(ma2.get(i));
			i++;
		}
		
		//test set
		ma2.set(1, (Integer)11111);
		
		System.out.println("\n7 :");
		i = 0;
		while (i < ma2.size()) {
			System.out.println(ma2.get(i));
			i++;
		}
		//test toString
		System.out.println(ma2.toString());
	}
}
