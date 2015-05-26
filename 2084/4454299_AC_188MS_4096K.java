import java.math.*;
import java.util.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger[] Catalan=new BigInteger[101];
		Catalan[0]=BigInteger.ONE;
		Catalan[1]=BigInteger.ONE;
		for(int i=2;i<=100;++i)
		{
			Catalan[i]=BigInteger.ZERO;
			for(int j=i-1;j>=0;--j)
			{
				Catalan[i]=Catalan[i].add(Catalan[j].multiply(Catalan[i-1-j]));
			}
		}
		Scanner cin=new Scanner(System.in);
		while(true)
		{
			int n=cin.nextInt();
			if(n==-1)
			{
				break;
			}
			System.out.println(Catalan[n]);
		}
	}
}
