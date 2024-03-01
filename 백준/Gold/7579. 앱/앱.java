import java.util.Scanner;

public class Main {

	static int[] memory = new int[105];
	static int[] cost = new int[105];
	static int[][] dp = new int[105][10005];

	public static int app(int idx, int c) {
		if (dp[idx][c] != -1) {
			return dp[idx][c];
		}

		if (c < cost[idx]) {
			return dp[idx][c] = app(idx + 1, c);
		} else {
			return dp[idx][c] = Math.max(app(idx + 1, c), app(idx + 1, c - cost[idx]) + memory[idx]);
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int N = in.nextInt();
		int M = in.nextInt();

		for (int i = 0; i < N; i++) {
			int x = in.nextInt();
			memory[i] = x;
		}

		for (int i = 0; i < N; i++) {
			int x = in.nextInt();
			cost[i] = x;
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j <= 10000; j++) {
				dp[i][j] = -1;
			}
		}

		for (int i = 0; i <= 10000; i++) {
			int mem = app(0, i);

			if (mem >= M) {
				System.out.println(i);
				break;
			}
		}

	}
}
