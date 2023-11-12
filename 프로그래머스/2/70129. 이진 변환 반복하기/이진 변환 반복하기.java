class Solution {
    public int[] solution(String s) {
        int[] answer = new int[2];
        
        int cnt=0;
        int trn=0;
        
        while(!s.equals("1")) {
            StringBuilder sb = new StringBuilder();
            for(char c: s.toCharArray()) {
                if(c=='0') {
                    cnt+=1;
                    continue;
                }
                else
                {
                    sb.append(c);                    
                }
            }
            
            int c = sb.toString().length();
            s = Integer.toString(c, 2);
            //System.out.println(s);
            trn+=1;
        }
        answer[0]=trn;
        answer[1]=cnt;
        return answer;
    }
}