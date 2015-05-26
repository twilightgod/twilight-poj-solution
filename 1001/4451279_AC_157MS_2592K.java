//import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	public static void main(String args[]) throws Exception {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			BigDecimal m = cin.nextBigDecimal();
			int r = cin.nextInt();
			String s = m.pow(r).toPlainString();
			if (s.indexOf('.') != -1) {
				int i;
				for (i = s.length() - 1; i >= 0; --i) {
					if (s.charAt(i) == '0') {
						continue;
					} else {
						break;
					}
				}
				if (i != s.length() - 1) {
					s = s.substring(0, i+1);
				}
				if (s.charAt(s.length()-1) == '.') {
					s = s.substring(0,s.length()-1);
				}
			}
			if (s.charAt(0) == '0') {
				s = s.substring(1);
			}
			System.out.println(s);
		}

	}

}
