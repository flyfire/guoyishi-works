import java.io.File;
import java.io.IOException;
import java.io.OutputStream;

//20090522 Modified from ListAllFolderAndFiles.java

public class ListContent {
	
	private OutputStream _Output;
	public ListContent() {
	}
	
	public ListContent(OutputStream output, String path) throws IOException{
		setOutput(output);
		
		File file = new File(path);
		List(file, 0);
	}
	private void setOutput(OutputStream out) {
		_Output = out;
	}
	private void List(File file,int spaceNumber) throws IOException {
		File[] files = file.listFiles();
		
		if (file.isDirectory()) {
			
			PrintLine(spaceNumber++);
			_Output.write(("\\" + file.getName() + "\\" + "\r\n").getBytes());
			
			for (int i = 0; i < files.length; ++i) {
				List(files[i], spaceNumber);
			}
		} else if (file.isFile()){
			
			PrintSpace(spaceNumber++);
			_Output.write(("" + file.getName() + "\r\n").getBytes());
		}
		else {
			_Output.write(("Wrrong Path!").getBytes());
		}
	}
	
	private void PrintSpace(int spaceNumber) throws IOException {
		for (int i = 0; i < spaceNumber; ++i) {
			_Output.write(("    ").getBytes());
		}
	}
	
	private void PrintLine(int spaceNumber) throws IOException {
		for (int i = 0; i < spaceNumber; ++i) {
			_Output.write(("    ").getBytes());
		}
	}
}
