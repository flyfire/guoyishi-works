//7-21 GenericDemo.java by Yishi Guo
//20090610 http://meiyou.org
import java.util.ArrayList;
import java.util.Iterator;

public class GenericDemo {
	public static void main(String[] args) {
		ArrayList<Integer> a = new ArrayList<Integer>();
		
		int sum = 0;
		a.add(new Integer(1));
		a.add(new Integer(12));
		
		for (Iterator<Integer> i = a.iterator(); i.hasNext();) {
			sum += i.next().intValue();
		}
		
		System.out.println(sum);
	}
}