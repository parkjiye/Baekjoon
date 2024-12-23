import java.util.Arrays;

class Solution {
    public String solution(String s) {
        String[] stringArr = s.split(" ");
        int[] nums = new int[stringArr.length];
        int len = stringArr.length;
        
        for(int i=0;i<stringArr.length;i++){
            nums[i]=Integer.valueOf(stringArr[i]);
        }
        
        Arrays.sort(nums);
        StringBuilder sb = new StringBuilder();
        sb.append(String.valueOf(nums[0]));
        sb.append(" ");
        sb.append(String.valueOf(nums[stringArr.length-1]));
        String answer = sb.toString();
        
        return answer;
    }
}