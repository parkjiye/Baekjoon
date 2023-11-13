class Solution {
    boolean solution(String s) {
        
        s = s.toLowerCase();
        
        int cnt_p = s.length()- s.replace("p","").length();
        int cnt_y = s.length()- s.replace("y","").length();
        
        return cnt_p==cnt_y;
    }
}