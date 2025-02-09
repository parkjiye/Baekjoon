import java.util.*;

class Solution {
    
    private boolean[] primes = new boolean[10000000];
    private boolean[] visited = new boolean[9];
    private char[] nums;
    private int len;
    private Set<Integer> s = new HashSet<>();
    
    private void setPrime() {
        primes[0]=true;
        primes[1]=true;
        for(int i=2;i<10000000;i++){
            if(primes[i]) continue;
            int j=2;
            while(i*j<10000000) {
                primes[i*j]=true;
                j++;
            }
            
        }
    }
    
    private void makeNumber(int idx, String num) {
        if(idx==len){
            return;
        }
        else {
            for(int i=0;i<len;i++){
                if(!visited[i]) {
                    StringBuilder sb = new StringBuilder(num);
                    sb.append(nums[i]);
                    s.add(Integer.parseInt(sb.toString()));
                    visited[i]=true;
                    makeNumber(idx+1, sb.toString());
                    visited[i]=false;
                }
            }
        }
        return;
    }
    
    
    public int solution(String numbers) {
        setPrime();
        len = numbers.length();
        nums = numbers.toCharArray();
        //System.out.println(Arrays.toString(nums));
        makeNumber(0, "");
        //System.out.println(s);
        int answer = 0;
        
        for(Integer i:s){
            if(!primes[i]) answer+=1;
        }
        return answer;
    }
}