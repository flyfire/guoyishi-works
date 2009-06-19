//7-17 LinkedListDemo.java by Yishi Guo
//20090609 http://meiyou.org
import java.util.ArrayList;
import java.util.LinkedList;

public class LinkedListDemo {
	public static void main(String[] args) {
		LinkedList ll = new LinkedList();
		System.out.println("List的初始大小: " + ll.size());
		for (int i = 0; i < 39; i++) {
			ll.add(i);
		}
		
		System.out.println("添加元素后的大小: " + ll.size());
		
		System.out.println("List中的内容: " + ll);
		
		ll.remove(22);
		
		ll.remove(2);
		
		System.out.println("是否包含元素111: " + ll.contains(111));
		
		ArrayList al = new ArrayList(ll);
		
		ll.clear();
		System.out.println("ll是否为空: " + ll.isEmpty());
		ll.addAll(al);
		System.out.println("List中的内容: " + ll);
		ll.addFirst(11);
		ll.addLast(33);
		System.out.println("List中的内容: " + ll);
	}
}
