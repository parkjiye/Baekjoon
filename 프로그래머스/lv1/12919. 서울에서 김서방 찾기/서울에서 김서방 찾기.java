class Solution {
    public String solution(String[] seoul) {
        String answer = "";
        
        for(int i=1;i<=seoul.length;i++)
        {
            if(seoul[i-1].equals("Kim"))
            {
                answer="김서방은 "+(i-1)+"에 있다";
            }
        }
        return answer;
    }
}