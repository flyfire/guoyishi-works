package pro4;
import pro3.*;
public class Demopro4 {
	public static void main(String[] args) {
		Demopro3 aDemo1 = new Demopro3();
		//����ʹ��protected,���ܱ����ķ���
		//aDemo1.method();
		aDemo1.a = 10;
		int a = aDemo1.a;
		System.out.println("Demopro3 �еĹ�����Ա����a��ֵ:" + a);
	}
}