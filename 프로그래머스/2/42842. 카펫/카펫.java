class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int outer = brown/2+1;
        
        for(int i=3;i<=outer-i+1;i++) {
            int col = i;
            int row = outer-i+1;
            //System.out.println(col + " "+row);
            
            if((col-2)*(row-2)==yellow) {
                answer[0]=row;
                answer[1]=col;
            }
        }
        
        return answer;
    }
}