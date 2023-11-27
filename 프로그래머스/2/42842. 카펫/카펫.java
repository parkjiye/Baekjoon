class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {};
        
        for(int i=1;i<=5000;i++) {
            for(int j=i;j<=5000;j++) {
                
                int b = (j+i-2)*2;
                int y = i*j-b;
                
                if(brown==b && yellow==y) {
                    answer = new int[] {j, i};
                }
            }
        }
        
        return answer;
    }
}