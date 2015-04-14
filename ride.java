/*
ID: iamnotnad1
LANG: JAVA
TASK: ride
*/
import java.io.*;
import java.util.*;

class ride 
{
  public static void main (String [] args) throws IOException 
  {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("ride.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st;
	 
	 while (f.ready())
	 {
	 	String name, comet;
		st = new StringTokenizer(f.readLine());
		name = st.nextToken();
		st = new StringTokenizer(f.readLine());
		comet = st.nextToken();
		
		int name_sum, comet_sum;
		name_sum = comet_sum = 1;
		for (int i = 0; i < name.length(); i++)
			name_sum *= (name.charAt(i) - 64);
		for (int j = 0; j < comet.length(); j++)
			comet_sum *= (comet.charAt(j) - 64);
		
		if ((name_sum % 47) == (comet_sum % 47))
			out.println("GO");
		else
			out.println("STAY");
		
	 }
	 /*
						  // Get line, break into tokens
    int i1 = Integer.parseInt(st.nextToken());    // first integer
    int i2 = Integer.parseInt(st.nextToken());    // second integer
    out.println(i1+i2);                           // output result
	 */
    out.close();                                  // close the output file
    System.exit(0);                               // don't omit this!
  }
}