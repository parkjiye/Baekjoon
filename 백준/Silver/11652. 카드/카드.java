import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {

  private static Map<String, Integer> map = new HashMap<>();

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();

    for(int i=0;i<N;i++) {
      String str = sc.next();
      map.put(str, map.getOrDefault(str, 0) + 1);
    }

    String minValue = String.valueOf(Long.MAX_VALUE);
    int maxCnt = 0;

    for (Entry<String, Integer> entry : map.entrySet()) {
      if(maxCnt<entry.getValue()) {
        maxCnt = entry.getValue();
        minValue = entry.getKey();
      } else if(maxCnt==entry.getValue() && Long.parseLong(minValue)>Long.parseLong(entry.getKey())) {
        maxCnt = entry.getValue();
        minValue = entry.getKey();
      }
    }
    System.out.println(minValue);
  }

}
