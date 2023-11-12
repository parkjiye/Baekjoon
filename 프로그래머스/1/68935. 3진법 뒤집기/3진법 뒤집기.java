class Solution {
    public int solution(int n) {
        int answer = 0;
        
        String s = Integer.toString(n,3);
        StringBuilder sb = new StringBuilder();
        
        for(char c: s.toCharArray()) {
            sb.append(c);
        }
        
        sb = sb.reverse();
        s = sb.toString();
        
        return Integer.valueOf(s, 3);
    }
}