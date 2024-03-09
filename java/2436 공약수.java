import java.io.*;

class Main {

	private static long gcd, lcm;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		gcd = Long.parseLong(input[0]);
		lcm = Long.parseLong(input[1]);
		long multi = gcd * lcm;
		long ans1 = Integer.MAX_VALUE;
		long ans2 = Integer.MAX_VALUE;
		for (long i = gcd; i * i <= multi; i += gcd) {
			if (multi % i == 0) {
				if (calGcd(i, multi / i) == gcd) {
					if (ans1 + ans2 > i + (multi / i)) {
						ans1 = i;
						ans2 = multi / i;
					}
				}
			}
		}
		bw.write(ans1 + " " + ans2);
		bw.close();
		br.close();
	}

	private static long calGcd(long a, long b) {
		if (b == 0)
			return a;
		return calGcd(b, a % b);
	}
}
