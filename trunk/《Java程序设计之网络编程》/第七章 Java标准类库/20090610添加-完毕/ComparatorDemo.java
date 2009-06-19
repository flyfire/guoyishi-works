//Wrong!!!

//7-24 ComparatorDemo.java by Yishi Guo
//20090610 http://meiyou.org
import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;
class ComparatorDemo implements Comparator{
	public int compare(Object a, Object b) {
		String aStr, bStr;
		aStr = (String) a;
		bStr = (String) b;
		return bStr.compareTo(aStr);
	}
}

class ComparatorInTreeSet {
	public static void main(String[] args) {
		TreeSet ts = new TreeSet(new ComparatorDemo());
		ts.add("C");
		ts.add("A");
		ts.add("B");
		ts.add("E");
		ts.add("F");
		ts.add("D");
		
		Iterator i = ts.iterator();
		while (i.hasNext()) {
			Object element = i.next();
			System.out.println(element + " ");
		}
	}
}
