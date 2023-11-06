class Solution {
    private static final int[] dx={-1, 1, 0, 0};
    private static final int[] dy={0, 0, -1, 1};
    
    private static final int[] mx={-1, 1, 1, -1};
    private static final int[] my={1, 1, -1, -1};
    
    public int findRoom(char[][] arr) {
        
        for(int i=0;i<5;i++) {
            
            for(int j=0;j<5;j++) {
                
                if(arr[i][j]=='P') {
                    //상하좌우 탐색
                    for(int k=0;k<4;k++) {
                        
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                            
                        if(nx>=0 && ny>=0 && nx<5 && ny<5) {
                            if(arr[nx][ny]=='P') {
                                return 0;
                            }
                        }
                    }
                    
                    for(int k=0;k<4;k++) {
                        int nx = i+dx[k]*2;
                        int ny = j+dy[k]*2;
                        
                        if(nx>=0 && ny>=0 && nx<5 && ny<5)
                        {
                            if(arr[nx][ny]=='P'&& arr[nx-dx[k]][ny-dy[k]]=='O')
                            {
                                return 0;
                            }
                        }
                    }
                    
                    for(int k=0;k<4;k++) {
                        int nx=i+mx[k];
                        int ny=j+my[k];
                        
                        if(nx>=0 && ny>=0 && nx<5 && ny<5) {
                            if(arr[nx][ny]=='P')
                            {
                                if(k==0&&arr[nx][ny-1]=='X'&&arr[nx+1][ny]=='X')
                                {
                                    continue;
                                }
                                if(k==1&&arr[nx-1][ny]=='X'&&arr[nx][ny-1]=='X')
                                {
                                    continue;
                                }
                                if(k==2&&arr[nx][ny+1]=='X'&&arr[nx-1][ny]=='X')
                                {
                                    continue;
                                }
                                if(k==3&&arr[nx][ny+1]=='X'&&arr[nx+1][ny]=='X')
                                {
                                    continue;
                                }
                                else {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return 1;
    }
    
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
                
        for(int r=0;r<5;r++)
        {
            char[][] arr = new char[5][5];
            for(int i=0;i<5;i++)
            {
                arr[i]=places[r][i].toCharArray();
            }
            
            answer[r]=findRoom(arr);
        }
        
        return answer;
    }
}