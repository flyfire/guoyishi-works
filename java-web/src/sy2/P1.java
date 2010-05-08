////////////////////////////////////
// Data:        2010-05-08
// Coder:       Yishi Guo
// Where:       1213
// Copy From:   wl
// About:       sy2-P1
////////////////////////////////////
package sy2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class P1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket( 8080 );
			try {
				while( true ) {
					Socket s = ss.accept();
					try {
						BufferedReader in = new BufferedReader( new InputStreamReader( s.getInputStream()));
						BufferedWriter out = new BufferedWriter( new OutputStreamWriter( s.getOutputStream()));
						out.write("HTTP/1.1 200 OK\r\n" );
						out.write( "Content-Type: text/html;charset=iso8859-1\r\n" );
						out.write( "\r\n" );
						out.write( "<html>" );
						out.write( "<head><title>BACK INFORMATION</title></head>" );
						out.write( "<body>" );
						out.write( "<table>" );
						String st = in.readLine();
						String[] sst = st.split( " " );
						if( !"GET".equalsIgnoreCase( sst[0] ) ) {
							continue;
						}
						while ( ( st = in.readLine() ) != null ) {
							if ( "".equals( st ) ) {
								break;
							}
							int i = st.indexOf( ':' );
							out.write( "<tr>" );
							out.write( "<td>" );
							out.write( st.substring(0,i) );
							out.write( "</td>" );
							out.write( "<td>" );
							out.write( st.substring(i+1));
							out.write( "</td>" );
							out.write( "</tr>" );
						}
						out.write( "</table>" );
						out.write( "</body>" );
						out.write( "</html>" );
						out.close();
						in.close();
					} finally {
						s.close();
					}
				}
			} finally{
				ss.close();
			}
		} catch ( IOException ex ) {
			ex.printStackTrace();
		}
	}
}