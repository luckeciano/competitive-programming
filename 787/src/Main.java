import java.util.*;

import java.math.BigInteger;

public class Main {
	public static void main (String[] args) throws java.lang.Exception
	{
		
		BigInteger vA[] = new BigInteger[105];
		Scanner scanner = new Scanner (System.in);
		while (scanner.hasNextInt()) {
			int A = scanner.nextInt();
			
			int i = 0;
			while (A != -999999) {
				BigInteger nA = new BigInteger(String.valueOf(A));
				vA[i] = nA;
				A = scanner.nextInt();
				i++;
			}
			
			BigInteger maxProd = vA[0];
			for (int k = 0; k < i; k++) {
				BigInteger prod = BigInteger.ONE;
				for (int j = k; j < i; j++) {
					prod = prod.multiply(vA[j]);
					maxProd = maxProd.max(prod);
				}
								
			}
			System.out.println(maxProd.toString());
		}
		 
		scanner.close();
	}

}
