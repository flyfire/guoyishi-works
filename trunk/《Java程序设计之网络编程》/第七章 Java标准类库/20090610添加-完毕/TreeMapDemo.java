//7-23 TreeMap.java by Yishi Guo
//20090610 http://meiyou.org
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class TreeMapDemo {
	public static void main(String[] args) {
		TreeMap<String, Double> tm = new TreeMap<String, Double>();
		tm.put("E", new Double(3444.444));
		tm.put("A", new Double(222.22));
		tm.put("C", new Double(323));
		tm.put("D", new Double(33));
		tm.put("A", new Double(442.323));
		tm.put("H", new Double(323.11));
		
		Set<String> set = tm.keySet();
		
		Iterator<String> i = set.iterator();
		
		while (i.hasNext()) {
			String key = i.next();
			System.out.println(key + ": " + tm.get(key).doubleValue());
		}
		
		double balance = tm.get("D").doubleValue();
		tm.put("D", new Double(balance + 1000));
		System.out.println("D's new balance: " + tm.get("D"));
	}
}
