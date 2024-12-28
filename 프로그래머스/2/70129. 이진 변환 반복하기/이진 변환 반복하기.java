class Solution {
    
    public int[] solution(String str) {
        int cnt=0;
        int loop=0;
        
        while(!str.equals("1")){
            StringBuilder sb = new StringBuilder();
        
            for(int i=0;i<str.length();i++){
                if(str.charAt(i)=='1') sb.append('1');
                else cnt+=1;
            }
        
            str = sb.toString();
            str = Integer.toBinaryString(str.length());
            loop+=1;
            //System.out.println(str);
        }
        
        
        int[] answer = {loop, cnt};
        return answer;
    }
}