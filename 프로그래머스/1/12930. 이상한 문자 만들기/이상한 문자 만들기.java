class Solution {
    public String solution(String s) {
        
        StringBuilder sb = new StringBuilder();
        char[] arr = s.toCharArray();
        
        int wordcnt=0;
        
        for(int i=0;i<arr.length;i++) {
            if(arr[i]==' ') {
                sb.append(' ');
                wordcnt=0;
            }
            else if(wordcnt%2==0) {
                sb.append(Character.toUpperCase(arr[i]));
                wordcnt+=1;
            }
            else {
                sb.append(Character.toLowerCase(arr[i]));
                wordcnt+=1;
            }
            
        }
        
        String answer = sb.toString();
        return answer;
    }
}