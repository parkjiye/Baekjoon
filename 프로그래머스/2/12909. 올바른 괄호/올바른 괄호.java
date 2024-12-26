import java.util.Stack;

class Solution {
    boolean solution(String s) {
        
        Stack<Integer> st = new Stack();
        boolean answer = true;
        
        for(int i=0;i<s.length();i++)
        {
            char c = s.charAt(i);
            
            if(c=='(') st.push(0);
            else {
                if(st.empty()) {
                    answer = false;
                    break;
                }
                
                if(st.peek()==0){
                    st.pop();
                } else {
                    answer = false;
                    break;
                }
            }
        }
        
        if(!st.empty()) answer = false;
        
        return answer;
    }
}