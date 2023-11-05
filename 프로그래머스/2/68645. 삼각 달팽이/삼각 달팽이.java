class Solution {
    public int[] solution(int n) {
        
        int [][] arr = new int[n][n];
        
        int[] dx={1, 0, -1};
        int[] dy={0, 1, -1};
        
        int total;
        
        if(n%2==0)
        {
            total = (1+n)*(n/2);
        }
        else
        {
            total = (1+n)*(n/2) + (n/2)+1;
        }
        
        int[] answer = new int[total];
        
        int cnt=1;
        int i=-1;
        int j=0;
        int d=0;
        int cycle=n;
        
        while(cnt<=total)
        {
            for(int k=0;k<cycle;k++)
            {
                
                i+=dx[d%3];
                j+=dy[d%3];
                arr[i][j]=cnt;
                //System.out.println(cnt+" "+i+" "+j+" "+k);
                cnt+=1;
            }
            d+=1;
            cycle--;
        }
        int idx=0;
        
        for(int t=0;t<n;t++)
        {
            for(int l=0;l<=t;l++)
            {
                //System.out.println(arr[t][l]);
                answer[idx]=arr[t][l];
                idx+=1;
            }
        }
        return answer;
    }
}