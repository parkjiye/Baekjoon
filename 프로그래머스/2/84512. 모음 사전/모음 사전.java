import java.util.List;
import java.util.ArrayList;

class Solution {
    
    List<String> arr = new ArrayList<>();
    char[] vowel={'A','E','I','O','U'};
    
    private void backtracking(int idx, String s) {
        
        if(idx==5) {
            return;
        }
        else {
            for(int i=0;i<5;i++) {
                arr.add(s+vowel[i]);
                backtracking(idx+1, s+vowel[i]);
            }
        }
    }
    public int solution(String word) {
        int answer = 0;
        int cnt = 1;
        
        backtracking(0, "");
        
        for(String s:arr) {
            if(s.equals(word)) {
                answer = cnt;
                break;
            }
            else {
                cnt+=1;
            }
        }
        return answer;
    }
}