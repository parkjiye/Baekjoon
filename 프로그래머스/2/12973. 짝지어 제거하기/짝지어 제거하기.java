import java.util.*;

class Solution
{
    public int solution(String s)
    {
        Stack<Character> st = new Stack<Character>();
        
        for(int i=0;i<s.length();i++) {
            
            if(st.empty()) {
                st.push(s.charAt(i));
            }
            else if(st.peek().equals(s.charAt(i))){
                st.pop();
            }
            else {
                st.push(s.charAt(i));
            }
        }
        
        if(st.empty()) return 1;
        else return 0;

    }
}