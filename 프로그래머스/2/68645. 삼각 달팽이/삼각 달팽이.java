class Solution {
    public int x = 0;
    public int y = 0;
    public int[][] arr;
    public int num=1;
    
    public void moveRight(int n){
        for(int i=0;i<n;i++){
            arr[x][y]=num;
            num+=1;
            y+=1;
        }
        y-=1;
    }
    
    public void moveDown(int n){
        for(int i=0;i<n;i++){
            arr[x][y]=num;
            num+=1;
            x+=1;
        }
        x-=1;
    }
    
    public void moveDiag(int n){
        for(int i=0;i<n;i++){
            arr[x][y]=num;
            num+=1;
            x-=1;
            y-=1;
        }
        x+=1;
        y+=1;
    }
    
    public int[] solution(int n) {
        arr = new int[n][n];
        int cnt = n;
        
        while(cnt>0){
            moveDown(cnt);
            y+=1;
            cnt-=1;
            if(cnt<=0) break;
            
            moveRight(cnt);
            x-=1;y-=1;
            cnt-=1;
            if(cnt<=0) break;
            
            moveDiag(cnt);
            x+=1;
            cnt-=1;
            if(cnt<=0) break;
        }
        
        /*for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }*/
        
        int[] answer = new int[num-1];
        
        int tmp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                answer[tmp]=arr[i][j];
                tmp+=1;
            }
        }
        
        return answer;
    }
}