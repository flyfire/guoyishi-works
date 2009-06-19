//7-19 TreeSetDemo.java by Yishi Guo
//20090609 http://meiyou.org
import java.util.TreeSet;
public class TreeSetDemo {
	public static void main(String[] args) {
		TreeSet<String> ts = new TreeSet();
		ts.add("D");
		ts.add("E");
		ts.add("A");
		ts.add("C");
		ts.add("F");
		System.out.println(ts);
		System.out.println(ts.first());
		System.out.println(ts.last());
	}
}
