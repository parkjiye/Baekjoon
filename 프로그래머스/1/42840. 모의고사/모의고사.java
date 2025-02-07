import java.util.*;
import java.util.stream.*;

class Solution {
    private int[][] student = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    
    public int[] solution(int[] answers) {
        int[] score = {0, 0, 0};
        for(int i=0;i<answers.length;i++) {
            for(int j=0;j<3;j++) {
                if(answers[i]==student[j][i%student[j].length]) {
                    score[j]++;
                }
            }
        }
        final int max = Math.max(Math.max(score[0], score[1]), score[2]);
        
        return IntStream.range(0, 3).filter(i->score[i]==max).map(i->i+1).toArray();
    }
}