//7-12 MathDemo.java by Yishi Guo
//20090609 http://meiyou.org
public class MathDemo {
	public static void main(String[] args) {
		double radians = 2 * Math.PI;
		double d1 = 3.1415926;
		
		System.out.println("ceil����: " + Math.ceil(d1));
		System.out.println("Round����: " + Math.round(d1));
		System.out.println("floor����: " + Math.floor(d1));
		System.out.println("exp����: " + Math.exp(d1));
		System.out.println("pow����: " + Math.pow(Math.E, d1));
		System.out.println("sin����: " + Math.sin(Math.PI / 6));
		System.out.println("asin����: " + Math.asin(0.5));
		System.out.println("log����: " + Math.log(Math.E));
		System.out.println("�Ƕ�ת����: " + Math.toDegrees(radians));
		System.out.println("random ����1: " + Math.random());
		System.out.println("random ����2: " + Math.random());
		
	}
}
