class Solution {
    public int[] solution(long n) {
        StringBuilder sb = new StringBuilder();
        String s = Long.toString(n);
        
        for(int i=0;i<s.length();i++) {
            sb.append(s.charAt(i));
        }
        
        sb = sb.reverse();
        s = sb.toString();
        
        char[] arr= new char[s.length()];
        arr = s.toCharArray();
        int[] answer = new int[s.length()];
        
        for(int i=0;i<arr.length;i++) {
            answer[i]=arr[i]-'0';
        }
        
        
        return answer;
    }
}