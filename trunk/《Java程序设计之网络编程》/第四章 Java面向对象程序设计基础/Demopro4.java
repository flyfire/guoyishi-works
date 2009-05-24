package pro4;
import pro3.*;
public class Demopro4 {
	public static void main(String[] args) {
		Demopro3 aDemo1 = new Demopro3();
		//不能使用protected,即受保护的方法
		//aDemo1.method();
		aDemo1.a = 10;
		int a = aDemo1.a;
		System.out.println("Demopro3 中的公共成员变量a的值:" + a);
	}
}