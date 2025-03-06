
import java.util.Scanner;

public class Main {

  private static Integer[] switches;
  private static int size;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    size = sc.nextInt();
    switches = new Integer[size + 1];

    for (int i = 1; i <= size; i++) {
      int on = sc.nextInt();
      switches[i] = on;
    }

    int K = sc.nextInt();
    for (int i = 1; i <= K; i++) {
      int sex = sc.nextInt();
      int num = sc.nextInt();
      if (sex == 1) {
        male(num);
      } else {
        female(num);
      }

    }

    for (int i = 1; i <= size; i++) {
      System.out.print(switches[i] + " ");
      if (i % 20 == 0) {
        System.out.println();
      }
    }
  }

  private static void female(int num) {
    switches[num] = switches[num] == 1 ? 0 : 1;
    int prev = num - 1;
    int next = num + 1;

    while (true) {
      if (prev <= 0 || next > size) {
        break;
      }

      if (switches[prev] == switches[next]) {
        switches[prev] = switches[prev] == 1 ? 0 : 1;
        switches[next] = switches[next] == 1 ? 0 : 1;
        prev--;
        next++;
      } else {
        break;
      }
    }
  }

  private static void male(int num) {
    int cur = num;
    while (cur <= size) {
      switches[cur] = switches[cur] == 1 ? 0 : 1;
      cur += num;
    }
  }
}
