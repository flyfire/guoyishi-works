//20090320 Demopub2.java
package pub2;
import pub1.*;
class Demopub2 {
	public static void main(String[] args) {
		Demopub1 aDemo1 = new Demopub1();
		aDemo1.method();
		aDemo1.a = 10;
		int a = aDemo1.a;
		System.out.println("aDemo1 中的公共成员变量a的值:" + a);
	}
}