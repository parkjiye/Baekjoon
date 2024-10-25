
import static java.lang.Math.pow;

import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int H = sc.nextInt();
    int x = sc.nextInt();

    long div = (long) pow(10, 9) +7;
    long answer=0;
    long cnt=1;

    for(int i=0;i<H;i++)
    {
      cnt*=x;
      cnt%=div;
      int h = sc.nextInt();
      answer += h*cnt;
      answer%=div;
    }

    System.out.println(answer);
  }
}
