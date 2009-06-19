//7-18 HashSetDemo.java by Yishi Guo
//20090609 http://meiyou.org
import java.util.HashSet;
public class HashSetDemo {
	public static void main(String[] args) {
		HashSet<String> hs = new HashSet();
		hs.add("A");
		hs.add("B");
		hs.add("C");
		hs.add("D");
		hs.add("E");
		hs.add("F");
		hs.add("A");
		System.out.println(hs);
	}
}
