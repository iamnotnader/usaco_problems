/*
ID: iamnotnad1
LANG: JAVA
TASK: milk2
*/
import java.io.*;
import java.util.*;

class milk2
{
  public static void main (String [] args) throws IOException 
  {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("milk2.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
	 StringTokenizer st = new StringTokenizer(f.readLine());
	 int N = Integer.parseInt(st.nextToken());
	 MilkMan[] men = new MilkMan[N];
	 
	 for (int i = 0; i < N; i++)
	 {
	 	st = new StringTokenizer(f.readLine());
	 	men[i] = new MilkMan(Integer.parseInt(st.nextToken()), 
									Integer.parseInt(st.nextToken()));
	 }
	 
	 Arrays.sort(men);
	 
	 for (int i = 0; i < N; i++)
	 {
	 	System.out.println(men[i].start + " " + men[i].end);
	 }
	 
	 out.close();                                  // close the output file
    System.exit(0);   
 }
 
 private static class MilkMan implements Comparable<MilkMan>
{
	public int start;
	public int end;
	
	public MilkMan(int s, int e)
	{
		start = s;
		end = e;
	}
	
	public int compareTo(MilkMan b)
	{
		if (start > b.start)
			return 1;
		else if (start < b.start)
			return -1;
		else
		{
			if (end > b.end)
				return -1;
			else if (end < b.end)
				return 1;
			else
				return 0;
		}
	}
}
}