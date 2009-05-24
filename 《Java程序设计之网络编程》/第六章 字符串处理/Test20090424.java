//20090424 by Yishi Guo
//20090425 Added
class Append {
	public Append() {
		StringBuffer sbfSource = new StringBuffer("1 + 2 = ");
		int nThree = 3;
		sbfSource.append(nThree);
		System.out.println(sbfSource.toString());
	}
}

class Insert {
	public Insert() {
		StringBuffer sbfSource = new StringBuffer("1 +  = 2");
		int nOne = 1;
		sbfSource.insert(4, nOne);
		System.out.println(sbfSource.toString());
	}
}

class CharAt {
	public CharAt() {
		StringBuffer sbfSource = new StringBuffer(10);
		sbfSource.append("meiyou.org");
		char ch = sbfSource.charAt(3);
		System.out.println(ch);
	}
}

class GetChars {
	public GetChars() {
		StringBuffer sbfSource = new StringBuffer("meiyou.org");
		char[] str = {'A', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
		System.out.println(String.valueOf(str));
		sbfSource.getChars(3, 5, str, 0);
		System.out.println(sbfSource + " " + String.valueOf(str));
		
	}
}

class Delete {
	public Delete() {
		StringBuffer sbfSource = new StringBuffer("You are the best");
		System.out.println(sbfSource);
		sbfSource.delete(0, 3);
		System.out.println(sbfSource);
		sbfSource.deleteCharAt(3);
		System.out.println(sbfSource);
	}
}

class Replace2 {
	public Replace2() {
		StringBuffer sbfSource = new StringBuffer("You are the best!");
		String str = "I'm";
		sbfSource.replace(0, 7, str);
		System.out.println(str + " " + sbfSource);
	}
}

class SubString2 {
	public SubString2() {
		StringBuffer sbfSource = new StringBuffer("You are the best?");
		String str = sbfSource.substring(4, 7);
		System.out.println(sbfSource + " " +str);
	}
}

class Reverse {
	public Reverse() {
		StringBuffer sbfSource = new StringBuffer("meiyou.org");
		String str = sbfSource.reverse().toString();
		System.out.println(sbfSource + " " + str);
		
		String strSource = new String("meiyou.org");
		String strDest = reverseIt(strSource);
		System.out.println("strSource: " + strSource);
		System.out.println("strDest(reversed): " + strDest);
	}
	
	public static String reverseIt(String strSource) {
		StringBuffer sbfSource = new StringBuffer();
		for (int i = strSource.length() - 1; i >= 0; i--) {
			sbfSource.append(strSource.charAt(i));
		}
		return sbfSource.toString();
	}	
}

class Capacity {
	public Capacity() {
		StringBuffer sbfSource = new StringBuffer(10);
		sbfSource.append("Who?");
		System.out.println("Capacity: " + sbfSource.capacity());
		System.out.println("Length: " + sbfSource.length());
	}
}
public class Test20090424 {
	public static void main(String[] args) {
		new Append();
		new Insert();
		new CharAt();
		new GetChars();
		new Delete();
		new Replace2();
		new SubString2();
		new Reverse();
		new Capacity();
	}
}
