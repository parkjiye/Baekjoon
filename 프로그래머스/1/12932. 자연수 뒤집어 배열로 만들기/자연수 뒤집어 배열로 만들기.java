class Solution {
    public int[] solution(long n) {
        
        StringBuilder sb = new StringBuilder(Long.toString(n));
        sb = sb.reverse();
        String s = sb.toString();
        
        char[] arr = s.toCharArray();
        int[] answer = new int[arr.length];
        
        for(int i=0;i<arr.length;i++){
            answer[i]=Character.getNumericValue(arr[i]);
        }
        
        return answer;
    }
}