//7-20 IteratorDemo.java by Yishi Guo
//20090610 http://meiyou.org
import java.util.ArrayList;
import java.util.Iterator;
import java.util.ListIterator;

public class IteratorDemo {
	public static void main(String[] args) {
		ArrayList<String> al = new ArrayList();
		al.add("A");
		al.add("C");
		al.add("E");
		al.add("F");
		al.add("H");
		al.add("T");
		
		System.out.print("Original contents of List: ");
		Iterator iter = al.iterator();
		while (iter.hasNext()) {
			Object element = iter.next();
			System.out.print(element + " ");
		}
		
		System.out.println();
		ListIterator litr = al.listIterator();
		while (litr.hasNext()) {
			Object element = litr.next();
			litr.set(element + " ++ ");
		}
		
		System.out.print("Modified list forwards: ");
		iter = al.iterator();
		while (iter.hasNext()) {
			Object element = iter.next();
			System.out.print(element + " ");
		}
		
		System.out.println();
		System.out.print("Modified list backwards: ");
		
		while (litr.hasPrevious()) {
			Object element = litr.previous();
			System.out.print(element + " ");
		}
		
		System.out.println();
	}
}
