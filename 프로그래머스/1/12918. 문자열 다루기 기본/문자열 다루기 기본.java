class Solution {
    public boolean solution(String s) {
        
        boolean answer = (s.matches("[0-9]*") && (s.length()==4 || s.length()==6));
        
        return answer;
    }
}