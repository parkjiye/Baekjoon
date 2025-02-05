import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<arr.length;i++) {
            if(stack.empty()) stack.push(arr[i]);
            else {
                if(stack.peek()!=arr[i]) stack.push(arr[i]);
            }
        }
        
        int[] answer = new int[stack.size()];
        int len = stack.size();
        for(int i=0;i<len;i++){
            answer[len-i-1]=stack.pop();
        }

        return answer;
    }
}