import java.util.*;
import java.math.*;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			//BigDecimal a=new BigDecimal(cin.next());
			String s=cin.next();
			System.out.print(s+" [8] = ");
			s=s.substring(2);
			BigDecimal f=new BigDecimal("8");
			BigDecimal d=new BigDecimal("0");
			for(int i=0;i<s.length();++i)
			{
				BigDecimal t=new BigDecimal(s.charAt(i)-'0');
				d=d.add(t.divide(f));
				f=f.multiply(new BigDecimal("8"));
			}
			System.out.println(d.toPlainString()+" [10]");
		}
	}

}
