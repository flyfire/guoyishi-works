//7-25 CollectionsDemo.java by Yishi Guo
//20090610 http://meiyou.org
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.List;

public class CollectionsDemo {
	public static void main(String[] args) {
		LinkedList<Integer> ll = new LinkedList();
		ll.add(new Integer(-11));
		ll.add(new Integer(11));
		ll.add(new Integer(4));
		ll.add(new Integer(-112));
		ll.add(new Integer(32));
		ll.add(new Integer(337));
		
		Collections.sort(ll);
		System.out.println(ll);
		System.out.println("The position of 32 in list: " +
				Collections.binarySearch(ll, new Integer(32)));
		
		Comparator r = Collections.reverseOrder();
		
		Collections.sort(ll, r);
		Iterator li = ll.iterator();
		System.out.print("List sorted in reverse: ");
		while (li.hasNext()) {
			System.out.print(li.next() + " ");
		}
		
		System.out.println();
		int binarySearch = Collections.binarySearch(ll, new Integer(32), r);
		System.out.println("The position of 32 in list: " +
				binarySearch);
		
		Collections.shuffle(ll);
		
		li = ll.iterator();
		
		System.out.print("List shuffled: ");
		while (li.hasNext()) {
			System.out.print(li.next() + " ");
		}
		
		System.out.println();
		System.out.println("Minimum: " + Collections.min(ll));
		System.out.println("Maximum: " + Collections.max(ll));
		
		
		System.out.println("The position of 32 : " +
				binarySearch);
		
	}
}
