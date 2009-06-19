//7-16 ListToArray.java by Yishi Guo
//20090609 http://meiyou.org
import java.util.ArrayList;
public class ListToArray {
	public static void main(String[] args) {
		 ArrayList<Double> al = new ArrayList();
		 al.add(new Double(10.3));
		 al.add(new Double(20.4));
		 al.add(new Double(30.5));
		 al.add(new Double(40.6));
		 al.add(new Double(50.7));
		 al.add(new Double(60.8));
		 al.add(new Double(70.9));
		 System.out.println("Content: " + al);
		 Object a[] = al.toArray();
		 double sum = 0.0;
		 for (int i = 0; i < a.length; i++) {
			 sum += ((Double)a[i]).doubleValue();
		 }
		 
		 System.out.println("Sum: " + sum);
	}
}
