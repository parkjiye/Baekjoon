class Solution {
    boolean solution(String s) {
        
        s = s.toLowerCase();
        int p_cnt=0;
        int y_cnt=0;
        
        char[] arr = s.toCharArray();
        for(int i=0;i<arr.length;i++) {
            if(arr[i]=='p') p_cnt+=1;
            if(arr[i]=='y') y_cnt+=1;
        }

        return p_cnt==y_cnt?true:false;
    }
}