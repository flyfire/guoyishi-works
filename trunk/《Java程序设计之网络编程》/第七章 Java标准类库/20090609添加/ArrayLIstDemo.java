//7-15 ArrayListDemo.java by Yishi Guo
//20090609 http://meiyou.org
import java.util.ArrayList;
public class ArrayLIstDemo {
	public static void main(String[] args) {
		ArrayList<String> al = new ArrayList();
		System.out.println("List�ĳ�ʼ��С: " + al.size());
		al.add("A");
		al.add("B");
		al.add("C");
		al.add("D");
		al.add("E");
		al.add("F");
		al.add(1, "A2");
		System.out.println("����Ԫ�غ�Ĵ�С: " + al.size());
		
		System.out.println("List�е�����: " + al);
		
		al.remove("D");
		al.remove(2);
		System.out.println("ɾ��Ԫ�غ�Ĵ�С: " + al.size());
		System.out.println("����: " + al);
	}
}
