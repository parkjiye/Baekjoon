import java.util.List;
import java.util.ArrayList;

class Solution {
    private static final int[][] prob = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    
    public int[] solution(int[] answers) {
        int[] answer = {0, 0, 0};
        
        for(int i=0;i<3;i++) {
            for(int j=0;j<answers.length;j++) {
                if(answers[j]==prob[i][j%prob[i].length]) {
                    answer[i]+=1;
                }
            }
        }
        
        int max_value=0;
        
        for(int i=0;i<3;i++) {
            if(answer[i]>max_value) {
                max_value=answer[i];
            }
        }
        List<Integer> ans = new ArrayList<>();

        for(int i=0;i<3;i++) {
            if(answer[i]==max_value) {
                ans.add(i+1);
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}