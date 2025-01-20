import java.lang.Math;

class Solution {
    public int solution(String s) {
        int answer = Integer.MAX_VALUE;
        char[] arr = s.toCharArray();
        if(s.length()==1) answer=1;
        for(int i=1;i<s.length();i++){
            StringBuilder sb = new StringBuilder();
            String s1 = s.substring(0, i);
            int cnt=1;
            for(int j=i;j<s.length();j+=i){
                String s2;
                if(j+i>s.length()) s2 = s.substring(j);
                else s2 = s.substring(j, j+i);
                if(s1.equals(s2)) {
                    cnt+=1;
                }
                else {
                    if(cnt==1) {
                        sb.append(s1);
                    }
                    else {
                        sb.append(Integer.toString(cnt));
                        sb.append(s1);
                    }
                    s1 = s2;
                    cnt=1;
                }
            }
            if(cnt==1) sb.append(s1);
            else {
                sb.append(Integer.toString(cnt));
                sb.append(s1);
            }
            //System.out.println(sb.toString());
            answer = Math.min(answer, sb.toString().length());
        }
        return answer;
    }
}