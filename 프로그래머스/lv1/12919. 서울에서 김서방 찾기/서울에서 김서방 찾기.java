import java.util.*;

class Solution {
    public String solution(String[] seoul) {
        String answer = "";
        
        List<String> strlist = new ArrayList<>(Arrays.asList(seoul));
        int idx = strlist.indexOf("Kim");
        
        answer = "김서방은 "+(idx)+"에 있다";
        return answer;
    }
}