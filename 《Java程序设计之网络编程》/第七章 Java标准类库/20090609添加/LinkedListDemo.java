//7-17 LinkedListDemo.java by Yishi Guo
//20090609 http://meiyou.org
import java.util.ArrayList;
import java.util.LinkedList;

public class LinkedListDemo {
	public static void main(String[] args) {
		LinkedList ll = new LinkedList();
		System.out.println("List�ĳ�ʼ��С: " + ll.size());
		for (int i = 0; i < 39; i++) {
			ll.add(i);
		}
		
		System.out.println("���Ԫ�غ�Ĵ�С: " + ll.size());
		
		System.out.println("List�е�����: " + ll);
		
		ll.remove(22);
		
		ll.remove(2);
		
		System.out.println("�Ƿ����Ԫ��111: " + ll.contains(111));
		
		ArrayList al = new ArrayList(ll);
		
		ll.clear();
		System.out.println("ll�Ƿ�Ϊ��: " + ll.isEmpty());
		ll.addAll(al);
		System.out.println("List�е�����: " + ll);
		ll.addFirst(11);
		ll.addLast(33);
		System.out.println("List�е�����: " + ll);
	}
}
