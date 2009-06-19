//13-1 Create_Table.java by Yishi Guo
//20090613 http://meiyou.org
import java.sql.*;
public class Create_Table {
	public static void main(String[] args) {
		String JDriver = "sun.jdbc.odbc.JdbcOdbcDriver";
		
		String conURL = "jdbc:odbc:2009Test";
		try {
			Class.forName(JDriver);
		} catch (java.lang.ClassNotFoundException e) {
			System.out.println("forname: " + e.getMessage());
		}
		
		try {
			Connection con = DriverManager.getConnection(conURL);
			
			Statement s = con.createStatement();
			
			String query = "create table consumer(id char(10)," +
					"name char(15), totalMoney integer)";
			s.executeUpdate(query);
			s.close();
			con.close();
		} catch (SQLException e) {
			System.out.println("SQLException: " + e.getMessage());
		}
	}
}
