import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int t;
		Scanner cin=new Scanner(System.in);
		t=cin.nextInt();
		while(t--!=0){
			String sa=cin.next();
			String sb=cin.next();
			if(sa.charAt(0)=='+'){
				sa=sa.substring(1);
			}
			if(sb.charAt(0)=='+'){
				sb=sb.substring(1);
			}
			BigInteger a=new BigInteger(sa);
			BigInteger b=new BigInteger(sb);
			System.out.println(a.add(b).toString());
		}
	}

}
