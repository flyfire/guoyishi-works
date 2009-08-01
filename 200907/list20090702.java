//20090702 by Yishi Guo
import java.io.*;
import java.util.Date;
public class list20090702 {
	public static void main(String args[]) {
		File openDir = new File("C:\\WINDOWS\\system32");
		File[] openFiles = openDir.listFiles();
		for (int i = 0; i < openFiles.length; i++) {
			if (openFiles[i].isFile()) {
				long lasttime = openFiles[i].lastModified();
				//System.out.println(lasttime);
				Date time = new Date(lasttime);
				//System.out.println(time);
				Date needTime = new Date();
				needTime.setYear(106);
				needTime.setMonth(1);
				needTime.setDate(1);
				needTime.setHours(0);
				needTime.setMinutes(0);
				needTime.setSeconds(0);
				//System.out.println(needTime);
					if (time.after(needTime)) {
					String file = openFiles[i].toString();
						if (file.endsWith(".dll")) {
							//System.out.println(time);
							System.out.println(openFiles[i]);
						}
					}
			}
		}
	}
}