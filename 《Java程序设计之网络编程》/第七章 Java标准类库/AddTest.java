//20090515 Yishi Guo
//Test
import java.util.*;
public class AddTest {
	public static void main (String[] args) {
		HashSet<Double> hs = new HashSet<Double>();
		Iterator iter = hs.iterator();
		int i = 0;
		Double addAll = 0.0;
		while (i != 30) {
			Random rd = new Random();
			Double value = rd.nextDouble();
			hs.add(value);
			System.out.println((i++) + " : " + value);
			addAll += value;
		}
		System.out.println(addAll);
		/////////////////////////////////////////////
		Double sum = 0.0;
		
		iter = hs.iterator();
		
		while (iter.hasNext()) {
			sum += (Double)iter.next();
			System.out.println("Sum : " + sum);
		}
		System.out.println("Sum : " + sum);
		System.out.println("Average : " + sum / 30 + " DDDDDDDDDDDD");
	
		//////////////////////////////////////////////
		Double average = 0.0;
		iter = hs.iterator();
		while (iter.hasNext()) {
			average += (Double)iter.next();
			average /= 2;
			System.out.println("Average : " + average);
		}
		System.out.println("Average : " + average);
	}
}
