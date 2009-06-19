//7-22 HashMapDemo.java by Yishi Guo
//20090610 http://meiyou.org
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
public class HashMapDemo {
	public static void main(String[] args) {
		HashMap<String, Integer> hm = new HashMap<String, Integer>();
		
		hm.put("John", new Integer(96));
		hm.put("Tom", new Integer(97));
		hm.put("Jane", new Integer(98));
		hm.put("Hall", new Integer(99));
		hm.put("Smith", new Integer(100));
		
		Set set = hm.entrySet();
		Iterator<Map.Entry> i = set.iterator();
		
		while (i.hasNext()) {
			Map.Entry me = i.next();
			System.out.print(me.getKey() + ": ");
			System.out.println(me.getValue());
		}
		
		int balance = hm.get("John").intValue();
		hm.put("John", new Integer(balance + 100));
		System.out.println("John's new balance: " + hm.get("John"));
	}
}
