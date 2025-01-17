class Solution {
    public String solution(String s, int n) {
        char[] arr = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(arr[i]==' ') {
                sb = sb.append(arr[i]);
            }
            else {
                int num = (int)arr[i]+n;
                if(arr[i]<91 && num>=91) {
                    sb = sb.append((char)(num%91+65));
                }
                else if(arr[i]<123 && num>=123) {
                    sb = sb.append((char)(num%123+97));
                }
                else {
                    sb = sb.append((char)num);
                }
                
            }
            //System.out.println((int)arr[i] + n);
            
        }
        String answer = sb.toString();
        return answer;
    }
}