import java.util.*;

public class Gift {
    
        int got_present;
        int gave_present;
        int present_score;
    
        public Gift() {}
        
}

class Solution {
    
    public int solution(String[] friends, String[] gifts) {
        HashMap<String, Integer> m = new HashMap<>();
        int[][] arr = new int[55][55];
        int[] score = new int [55];
        Gift[] board = new Gift[55];
        int answer = 0;
        int num=0;
        
        for(String f:friends)
        {
            m.put(f, num);
            board[num] = new Gift();
            num+=1;
        }
        
        System.out.println(m.size());
                
        for(String g:gifts) {
            String tmp[]=g.split(" ");
            arr[m.get(tmp[0])][m.get(tmp[1])]+=1;
            board[m.get(tmp[0])].gave_present+=1;
            board[m.get(tmp[1])].got_present+=1;
        }
        
        for(int i=0;i<m.size();i++)
        {
            board[i].present_score = board[i].gave_present-board[i].got_present;
        }
        
        
        for(int i=0;i<m.size()-1;i++)
        {
            for(int j=i+1;j<m.size();j++)
            {
                //두 사람이 선물을 주고받은 기록이 있다면
                if(arr[i][j]>=0 || arr[j][i]>=0)
                {
                    if(arr[i][j]>arr[j][i])
                    {
                        score[i]+=1;
                    }
                    else if(arr[i][j]==arr[j][i])
                    {
                        if(board[i].present_score>board[j].present_score)
                        {
                            score[i]+=1;
                        }
                        else if(board[i].present_score<board[j].present_score)
                        {
                            score[j]+=1;
                        }
                    }
                    else
                    {
                        score[j]+=1;
                    }
                }
                else
                {
                    if(board[i].present_score>board[j].present_score)
                    {
                        score[i]+=1;
                    }
                    else if(board[i].present_score<board[j].present_score)
                    {
                        score[j]+=1;
                    }
                }
            }
        }
        
        for(int i=0;i<m.size();i++)
        {
            if(score[i]>answer)
            {
                answer = score[i];
            }
        }
        
        
        return answer;
    }
}