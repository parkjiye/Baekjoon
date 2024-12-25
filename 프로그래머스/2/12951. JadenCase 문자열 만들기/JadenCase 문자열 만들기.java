class Solution {
    public String solution(String s) {
        
        char[] arr = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        
        for(int i=0;i<arr.length;i++)
        {
            if(i==0) {
                String tmp ="";
                tmp+=arr[i];
                sb.append(tmp.toUpperCase());
            }
            else if(arr[i-1]==' ' && arr[i]!=' '){
                String tmp ="";
                tmp+=arr[i];
                sb.append(tmp.toUpperCase());
            }
            else if(arr[i]!=' '){
                String tmp ="";
                tmp+=arr[i];
                sb.append(tmp.toLowerCase());
            }
            else {
                sb.append(arr[i]);
            }
        }
        
        return sb.toString();
    }
}