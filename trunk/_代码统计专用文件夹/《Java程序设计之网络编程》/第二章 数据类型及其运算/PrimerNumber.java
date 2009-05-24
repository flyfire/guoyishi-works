public class PrimerNumber {
	public static void main(String[] args){
		int MAX = Integer.parseInt(args[0]);
		int SIZE = MAX / 3;
		int primeNo[] = new int[SIZE];
		int i,j,k,n;
		primeNo[0] = 2;
		n = 1;
		i = 1;
		j = 3;
		do {
			k = 0;
			while(k < n && (j % primeNo[k] != 0))
				++k;
			if (k == n) {
				primeNo[i] = j;
				++i;
				++n;				
			}
			j += 2;
		} while (j < MAX);
		System.out.println("All prime number between 2~" + MAX + " are: ");
		for (i = 0; i < primeNo.length; ++i) {
			System.out.print(" " + primeNo[i]);
			if ((i + 1) % 10 == 0)
				System.out.println();
		}
		System.out.println();
		System.out.println("the total number is: " + n);
	}
}