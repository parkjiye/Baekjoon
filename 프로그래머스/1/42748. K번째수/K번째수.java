import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        
        int[] answer = new int[commands.length];
        
        for(int i=0;i<commands.length;i++) {
            int s = commands[i][0]-1;
            int e = commands[i][1]-1;
            int p = commands[i][2]-1;
            
            int[] nums = new int[e-s+1];
            int t=0;
            for(int j=s;j<=e;j++){
                nums[t++]=array[j];
            }
            Arrays.sort(nums);
            answer[i]=nums[p];
        }
        return answer;
    }
}