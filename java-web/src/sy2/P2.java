/////////////////////////////////
// Data:       2010-05-08
// Coder:      Yishi Guo
// Where:      1213
// Copy From:  wl
// About:      sy2-P2
/////////////////////////////////
package sy2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class P2 {
	public static void main( String[] args ) {
		try {
			ServerSocket ss = new ServerSocket( 4321 );
			try {
				while ( true ) {
					Socket s = ss.accept();
					try {
						BufferedReader in = new BufferedReader( new InputStreamReader( s.getInputStream() ));
						BufferedWriter out = new BufferedWriter( new OutputStreamWriter( s.getOutputStream()));
						out.write( " HTTP/1.1 200 OK\r\n" );
						out.write( "Content-Type: text/html;charset=utf-8\r\n" );
						out.write( "\r\n" );
						String st = in.readLine();
						String[] sst = st.split( " " );
						if ( !"POST".equalsIgnoreCase( sst[0] ) ) {
							continue;
						}
						int length = 0;
						int i = 0;
						while ( ( st = in.readLine() ) != null ) {
							if ( "".equals( st ) ) {
								break;
							}
							i = st.indexOf( ':' );
							String name = st.substring( 0, i );
							if ( "Content-Length".equalsIgnoreCase(name) ) {
								length = Integer.parseInt(st.substring(i+1).trim() );
								break;
							}	
						}
						in.read(new char[2] );
						if ( length > 0 ) {
							char[] c = new char[length];
							in.read( c );
							String query = new String( c );
							try {
								i = query.indexOf( '&' );
								int first = Integer.parseInt(query.substring(query.indexOf('=')+1,i));
								int second = Integer.parseInt( query.substring(query.lastIndexOf( '=')+1));
								first += second;
								out.write( "<html>" );
								out.write( "<body>" );
								out.write( "<center><h1>SUM: " + first );
								out.write( "</h1></center>" );
								out.write( "</body>" );
								out.write( "</html>" );	
							} catch (NumberFormatException ex ) {
								out.write( "<html><body><h1>" );
								out.write( query );
								out.write( "</h1></body></html" );
								out.close();
								in.close();
							}
						}
						out.close();
						in.close();
					} finally {
						s.close();
					}
				}
			} finally {
				ss.close();
			}
		} catch ( IOException ex ) {
			ex.printStackTrace();
		}
	}
}