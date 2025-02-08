import java.util.*;

class Solution {
    private static final String[] OPERATORS = {"+", "-", "*"};
    private static boolean[] visited;
    private static List<Long> sum;

    private static void calculate(int idx, Deque<String> operand, Deque<String> operator) {
    if (idx == 3) {
      sum.add(Math.abs(Long.parseLong(operand.peek())));
      return;
    }

    for (int k = 0; k < 3; k++) {
      if (!visited[k]) {
        Deque<String> operand_tmp = new ArrayDeque<>(operand);
        Deque<String> operator_tmp = new ArrayDeque<>(operator);

        visited[k] = true;

        Deque<String> nxtoperand = new ArrayDeque<>();
        Deque<String> nxtoperator = new ArrayDeque<>();

        while (!operator_tmp.isEmpty()) {
          if (operator_tmp.peekFirst().equals(OPERATORS[k])) {
            long a = Long.parseLong(operand_tmp.pollFirst());
            long b = Long.parseLong(operand_tmp.pollFirst());
            operator_tmp.pollFirst();

            if (OPERATORS[k].equals("+")) {
              operand_tmp.offerFirst(String.valueOf(a + b));
            } else if (OPERATORS[k].equals("-")) {
              operand_tmp.offerFirst(String.valueOf(a - b));
            } else {
              operand_tmp.offerFirst(String.valueOf(a * b));
            }

          } else {
            nxtoperand.offerLast(operand_tmp.pollFirst());
            nxtoperator.offerLast(operator_tmp.pollFirst());
          }
          //System.out.println(operand_tmp + " " + nxtoperand);
          //System.out.println(operator_tmp + " " + nxtoperator);
        }

        nxtoperand.offerLast(operand_tmp.pollFirst());

        calculate(idx + 1, nxtoperand, nxtoperator);
        visited[k] = false;
      }
    }
  }
    
    public long solution(String expression) {
        char[] strarr = expression.toCharArray();
        visited = new boolean[3]; // 항상 새로 초기화
        sum = new ArrayList<>(); // sum 리스트 초기화
        Deque<String> operands = new ArrayDeque<>();
        Deque<String> operators = new ArrayDeque<>();
        
        String s="";
        for(int i=0;i<strarr.length;i++){
            if(strarr[i]=='+'||strarr[i]=='-'||strarr[i]=='*') {
                operands.add(s);
                operators.add(strarr[i]+"");
                s="";
            }
            else {
                s+=strarr[i];
            }
        }
        operands.add(s);
        
        calculate(0, operands, operators);
        
        return Collections.max(sum);
    }
}