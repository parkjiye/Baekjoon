class Solution {
    public String changeString(String s) {
        StringBuilder sb = new StringBuilder();
        int i=0;
        for(char c: s.toCharArray()) {
            if(i%2==0){
                if(Character.isLowerCase(c)) {
                    sb.append(Character.toUpperCase(c));
                }
                else {
                    sb.append(c);
                }
            }
            else {
                if(Character.isUpperCase(c)) {
                    sb.append(Character.toLowerCase(c));
                }
                else {
                    sb.append(c);
                }
            }
            i+=1;
        }
        return sb.toString();
    }
    
    public String solution(String s) {
        String answer = "";
        StringBuilder sb = new StringBuilder();
        StringBuilder ans = new StringBuilder();
        
        for(char c : s.toCharArray()) {
            if(!Character.isAlphabetic(c)) {
                if(sb.length()>=1) {
                    ans.append(changeString(sb.toString()));
                    sb = new StringBuilder();
                    ans.append(' ');
                }
                else {
                    ans.append(' ');
                }
            }
            else {
                sb.append(c);
            }
        }
        
        if(sb.length()>=1) {
            ans.append(changeString(sb.toString()));
        }
        
        return ans.toString();
    }
}