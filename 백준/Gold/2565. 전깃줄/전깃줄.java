import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static class Point implements Comparable<Point> {

		public final int left;
		public final int right;

		public Point(int left, int right) {
			this.left = left;
			this.right = right;
		}

		@Override
		public int compareTo(Point point) {
			return this.left - point.left;
		}
	}

	static Integer[] dp;
	static Point[] arr;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		dp = new Integer[505];
		arr = new Point[N];

		for (int i = 0; i < N; i++) {
			int x = in.nextInt();
			int y = in.nextInt();

			arr[i] = new Point(x, y);
		}

		for (int i = 0; i < N; i++) {
			dp[i] = 1;
		}

		Arrays.sort(arr);

		int answer = 0;

		for (int i = 1; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[i].right > arr[j].right) {
					dp[i] = Math.max(dp[i], dp[j] + 1);
				}
			}

			if (dp[i] > answer)
				answer = dp[i];
		}

		System.out.println(N - answer);

	}

}
