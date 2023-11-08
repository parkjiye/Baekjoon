class Solution {
    public String solution(String s, int n) {
        String answer = "";
        
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length();i++) {
            
            char c = s.charAt(i);
            
            if(c==' ')
            {
                sb.append(c);
            }
            else if(c<='Z' && c+n>'Z')
            {
                sb.append((char)(c+n-26));
            }
            else if(c>='a' && c+n>'z')
            {
                sb.append((char)(c+n-26));
            }
            else
            {
                sb.append((char)(c+n));
            }
        }
        
        answer = sb.toString();
        
        return answer;
    }
}