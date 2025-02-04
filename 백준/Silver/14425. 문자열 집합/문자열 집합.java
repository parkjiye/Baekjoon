
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();

    Set<String> set = new HashSet<>();
    for (int i = 0; i < N; i++) {
      String s = sc.next();
      set.add(s);
    }
    int answer = 0;
    for (int i = 0; i < M; i++) {
      String s = sc.next();
      if (set.contains(s)) {
        answer++;
      }
    }
    System.out.println(answer);
  }

}
