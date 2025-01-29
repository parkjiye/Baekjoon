class Solution {
    private static int w=0;
    private static int b=0;
    
    public void check(int x, int y, int d, int[][] arr){
        int tmp_w = 0;
        int tmp_b = 0;
        for(int i=x;i<x+d;i++) {
            for(int j=y;j<y+d;j++) {
                if(arr[i][j]==0) tmp_w++;
                else tmp_b++;
            }
        }
        
        if(tmp_w==0) b++;
        else if(tmp_b==0) w++;
        else {
            check(x, y, d/2, arr);
            check(x, y+d/2, d/2, arr);
            check(x+d/2, y, d/2, arr);
            check(x+d/2, y+d/2, d/2, arr);
        }
    }
    
    
    public int[] solution(int[][] arr) {
        check(0, 0, arr.length, arr);
        int[] answer = {w, b};
        return answer;
    }
}