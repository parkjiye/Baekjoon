class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = 0;
        answer = health;
        
        int cur_time=1;
        int combo_time=0;
        
        for(int[] a: attacks){
            
            if(answer<=0)
            {
                return -1;
            }
            
            if(a[0]==cur_time)
            {
                answer-=a[1];
                cur_time+=1;
            }
            else if(a[0]>cur_time)
            {
                combo_time = (a[0]-cur_time)/bandage[0];
                
                answer+=combo_time*bandage[2];
                answer+=(a[0]-cur_time)*bandage[1];  
                
                if(answer>health)
                {
                    answer = health;
                }
                answer-=a[1];
                cur_time=a[0]+1;
            }
            
            System.out.println(answer);
            
        }
        
        if(answer<=0)
        {
            return -1;
        }
        return answer;
    }
}