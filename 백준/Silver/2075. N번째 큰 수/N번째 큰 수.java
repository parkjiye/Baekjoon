
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {

  private static int N;
  private static Queue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());

    for (int i = 0; i < N; i++) {
      String[] s = br.readLine().split(" ");
      for (int j = 0; j < N; j++) {
        pq.offer(Integer.parseInt(s[j]));
      }
    }

    while(N>1) {
      pq.poll();
      N--;
    }
    System.out.println(pq.poll());
  }
}
