import java.io.*;
import java.util.*;
import java.math.*;

public class Main {


		public static void main(String args[]) throws Exception            
		{      
			Scanner cin=new Scanner(System.in);
			while(cin.hasNext())
			{
			BigDecimal m=cin.nextBigDecimal();
			int r=cin.nextInt();
			System.out.println(m.pow(r).toPlainString());
			}
			
		}
	

}
