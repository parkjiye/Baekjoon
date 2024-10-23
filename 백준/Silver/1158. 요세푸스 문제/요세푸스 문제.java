
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int K = sc.nextInt();

    Deque<Integer> q = new LinkedList<Integer>();

    for(int i = 1; i <= N; i++) {
      q.addLast(i);
    }

    System.out.print("<");

    while(!q.isEmpty()) {

      for (int i = 0; i < K - 1; i++) {
        int x = q.getFirst();
        q.removeFirst();
        q.addLast(x);
      }

      if (q.size() == 1) {
        System.out.print(q.getFirst() + ">\n");
      } else {
        System.out.print(q.getFirst() + ", ");
      }

      q.removeFirst();
    }
  }
}
