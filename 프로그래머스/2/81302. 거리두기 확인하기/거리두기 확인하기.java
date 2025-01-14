import java.util.*;

class Solution {
    private static int[] dx={-1, 1, 0, 0};
    private static int[] dy={0, 0, -1, 1};
    
    private char[][] map;
    
    public boolean checkParticipant(int x, int y, int d) {
        
        int t;
        if(d%2==0) t=d+1;
        else t=d-1;
        for(int k=0;k<4;k++) {
            if(k!=t) {
                int next_x = x+dx[k];
                int next_y = y+dy[k];
                
                if(next_x>=0 && next_x<5 && next_y>=0 && next_y<5) {
                    if(map[next_x][next_y]=='P') return false;
                }
                
            }
        }
        return true;
    }
    
    public boolean checkPartition(int x, int y) {
        for(int k=0;k<4;k++){
            int next_x = x+dx[k];
            int next_y = y+dy[k];
            
            if(next_x>=0 && next_x<5 && next_y>=0 && next_y<5) {
                if(map[next_x][next_y]=='P') return false;
                else if(map[next_x][next_y]=='O') {
                    if(!checkParticipant(next_x, next_y, k)) return false;
                }
            }
        }
        return true;
    }
    
    public int[] solution(String[][] places) {
        
        int[] answer = new int[places.length];
        Arrays.fill(answer, 1);
        
        for(int i=0;i<places.length;i++) {
            map = new char[5][5];
            for(int j=0;j<5;j++) {
                map[j]=places[i][j].toCharArray();
            }
            
            for(int j=0;j<5;j++) {
                for(int k=0;k<5;k++) {
                    if(map[j][k]=='P') {
                        if(!checkPartition(j, k)) {
                            answer[i]=0;
                        }
                    }
                }
            }
        }
        
        
        return answer;
    }
}