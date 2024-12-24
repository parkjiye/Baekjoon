import java.util.Arrays;

class Solution
{
    public int solution(int []A, int []B)
    {
        int answer = 0;
        
        Arrays.sort(A);
        Arrays.sort(B);
        
        int len = A.length;
        
        for(int i=0;i<len;i++){
            answer += A[i]*B[len-i-1];
        }

        return answer;
    }
}