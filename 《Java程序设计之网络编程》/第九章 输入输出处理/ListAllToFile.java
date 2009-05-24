import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

//20090522

public class ListAllToFile {
	private String _Dir = "";
	private FileOutputStream _SaveFile;
	
	public ListAllToFile() {
		
	}

	public ListAllToFile(String dir, String fileName) throws IOException {
		setDir(dir);
		setSaveFile(fileName);
		
		SaveContent();
		
		System.out.println("Save file: " + fileName);
	}
	
	public void setDir(String dir) {
		_Dir = dir;
	}
	
	public void setSaveFile(String fileName) throws IOException {
		_SaveFile = new FileOutputStream(fileName);
	}
	
	private void SaveContent() throws IOException {
		new ListContent(_SaveFile, _Dir);
	}
	
	
}
