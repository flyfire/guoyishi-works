import java.io.IOException;

//20090522 TEST class: ListAllFoldersAndFiles
public class TESTListAll {
	public static void main(String[] args) throws IOException {
		new ListAllFoldersAndFiles("D:/test");
		new ListAllToFile("F:/Works", "F-Works.txt");
	}
}
