import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();

		ArrayList<Integer> pos = new ArrayList<>();
		ArrayList<Integer> neg = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			int x = in.nextInt();

			if (x > 0) {
				pos.add(x);
			} else {
				neg.add(x);
			}

		}

		Collections.sort(pos, Collections.reverseOrder());
		Collections.sort(neg);

		int answer = 0;

		if (pos.size() != 0 && neg.size() == 0) {
			answer += pos.get(0);

			for (int i = M; i < pos.size(); i += M) {
				answer += pos.get(i) * 2;
			}
		} else if (pos.size() == 0 && neg.size() != 0) {
			answer += neg.get(0) * -1;

			for (int i = M; i < neg.size(); i += M) {
				answer += neg.get(i) * (-2);
			}
		} else if (pos.get(0) > neg.get(0) * -1) {
			answer += pos.get(0);

			for (int i = M; i < pos.size(); i += M) {
				answer += pos.get(i) * 2;
			}

			for (int i = 0; i < neg.size(); i += M) {
				answer += neg.get(i) * (-2);
			}
		} else {
			answer += neg.get(0) * -1;

			for (int i = 0; i < pos.size(); i += M) {
				answer += pos.get(i) * 2;
			}

			for (int i = M; i < neg.size(); i += M) {
				answer += neg.get(i) * (-2);
			}
		}

		System.out.println(answer);

	}

}
