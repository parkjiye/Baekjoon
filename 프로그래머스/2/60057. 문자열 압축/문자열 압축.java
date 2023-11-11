class Solution {
    public int solution(String s) {
        int answer = 10000;
        
        for(int i=1;i<=s.length();i++)
        {
            StringBuilder sb = new StringBuilder();
            String temp = s.substring(0, i);
            //System.out.println(temp);
            
            int num=1;
            
            for(int j=i;j<s.length();j+=i)
            {
                
                if(j+i>s.length())
                {
                    sb.append(s.substring(j));
                    break;
                }
                
                String cmp = s.substring(j, j+i);
                
                //System.out.println(temp + " "+ cmp + " " + num);
                if(cmp.equals(temp))
                {
                    num+=1;    
                }
                else
                {
                    if(num>1)
                    {
                        sb.append(Integer.toString(num));
                        sb.append(temp);
                    }
                    else
                    {
                        sb.append(temp);
                    }
                    num=1;
                    
                    temp=cmp;
                }
            }
            
            if(num>1)
            {
                sb.append(Integer.toString(num));
                sb.append(temp);
            }
            else
            {
                sb.append(temp);
            }
            
            //System.out.println(sb.toString());
            
            if(sb.toString().length()<answer)
            {
                answer = sb.toString().length();
            }
        }
        return answer;
    }
}