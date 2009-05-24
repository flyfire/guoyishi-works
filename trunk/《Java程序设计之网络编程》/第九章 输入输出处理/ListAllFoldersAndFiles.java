//20090522 Yishi Guo
import java.io.*;

public class ListAllFoldersAndFiles {
	public ListAllFoldersAndFiles() {
	}
	
	public ListAllFoldersAndFiles(String path){
		File file = new File(path);
		List(file, 0);
	}
	
	private static void List(File file,int spaceNumber) {
		File[] files = file.listFiles();
		
		if (file.isDirectory()) {
			
			PrintLine(spaceNumber++);
			System.out.print("\\" + file.getName() + "\\\n");
			
			for (int i = 0; i < files.length; ++i) {
				List(files[i], spaceNumber);
			}
		} else if (file.isFile()){
			
			PrintSpace(spaceNumber++);
			System.out.print("" + file.getName() + "\n");
		}
		else {
			System.out.println("Wrrong Path!");
		}
	}
	
	private static void PrintSpace(int spaceNumber) {
		for (int i = 0; i < spaceNumber; ++i) {
			System.out.print("    ");
		}
	}
	
	private static void PrintLine(int spaceNumber) {
		for (int i = 0; i < spaceNumber; ++i) {
			System.out.print("    ");
		}
	}
}
