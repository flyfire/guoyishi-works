//20090320 Main Argument
public class MainArgument {
	public static void main(String[] args) {
		for (int i = 0; i < args.length; ++i) {
			System.out.println("Argument[" + i + "]:" + args[i]);
		}
	}
}