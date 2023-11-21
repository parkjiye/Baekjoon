class Solution {
    
    public int[] answer = new int[2];
    
    public void quard(int x, int y, int n, int[][] arr) {
        
        if(n==1)
        {
            for(int i=x;i<x+n;i++) {
                for(int j=y;j<y+n;j++) {
                    answer[arr[i][j]]+=1;     
                }
            }
            return;
        }
        
        int sum=0;
        
        for(int i=x;i<x+n;i++) {
            for(int j=y;j<y+n;j++) {
                sum+=arr[i][j];        
            }
        }
        
        if(sum==0 || sum==n*n) {
            if(sum==0)
            {
                answer[0]+=1;
            }
            else
            {
                answer[1]+=1;
            }
        }
        else
        {
            quard(x, y, n/2, arr);
            quard(x, y+n/2, n/2,arr);
            quard(x+n/2, y, n/2,arr);
            quard(x+n/2, y+n/2, n/2,arr);
        }
        
    }
    public int[] solution(int[][] arr) {
        //int[] answer = {};
        System.out.println(arr.length);
        quard(0, 0, arr.length, arr);
        return answer;
    }
}