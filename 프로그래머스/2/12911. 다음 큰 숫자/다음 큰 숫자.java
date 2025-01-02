class Solution {
    public int solution(int n) {
        int answer = n+1;
        String curInt = Integer.toBinaryString(n);
        int cnt = curInt.length() - curInt.replace("1", "").length();
        
        while(true) {
            String nextInt = Integer.toBinaryString(answer);
            int nextcnt = nextInt.length() - nextInt.replace("1", "").length();
            
            if(cnt == nextcnt) {
                return answer;
            }
            else {
                answer+=1;
            }
            
        }
        
    }
}