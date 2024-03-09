import java.io.*;

class Main {

	private static long n;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		n = Long.parseLong(br.readLine());
		long pi = n;
		for (long i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0)
				pi = pi / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
		if (n != 1)
			pi = pi / n * (n - 1);
		bw.write(String.valueOf(pi));
		bw.close();
		br.close();
	}
}
