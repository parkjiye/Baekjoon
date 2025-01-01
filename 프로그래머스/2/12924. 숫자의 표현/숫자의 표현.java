import java.util.*;

class Solution {
    public int solution(int n) {
        HashSet<Integer> set = new HashSet<Integer>();
        int answer = 0;
        int sum=0;

        for(int i=1;i<=n;i++){
            sum+=i;
            set.add(sum);
        }
        
        Iterator<Integer> it = set.iterator();
        while(it.hasNext()) {
            int num = it.next();
            if(set.contains(num-n) || num==n){
                //System.out.println(num);
                answer+=1;
            }
        }
        
        return answer;
    }
}