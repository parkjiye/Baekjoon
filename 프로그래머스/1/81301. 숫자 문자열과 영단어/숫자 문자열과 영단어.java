class Solution {
    
    public char changetoNum(String tmp)
    {
        if(tmp.equals("zero"))
        {
            return '0';
        }
        else if(tmp.equals("one"))
        {
            return '1';
        }
        else if(tmp.equals("two"))
        {
            return '2';
        }
        else if(tmp.equals("three"))
        {
            return '3';
        }
        else if(tmp.equals("four"))
        {
            return '4';
        }
        else if(tmp.equals("five"))
        {
            return '5';
        }
        else if(tmp.equals("six"))
        {
            return '6';
        }
        else if(tmp.equals("seven"))
        {
            return '7';
        }
        else if(tmp.equals("eight"))
        {
            return '8';
        }
        else if(tmp.equals("nine"))
        {
            return '9';
        }
        else
        {
            return '*';
        }
    }
    
    public int solution(String s) {
        int answer = 0;
        
        StringBuilder sb = new StringBuilder();
        StringBuilder ans = new StringBuilder();
        
        for(char c:s.toCharArray())
        {
            if(c>='A' && c<='z')
            {
                sb.append(c);
                
                char tmp = changetoNum(sb.toString());
                
                if(tmp!='*')
                {
                    ans.append(tmp);
                    sb = new StringBuilder();
                }
            }
            else
            {
                ans.append(c);
            }
        }
                
        return Integer.parseInt(ans.toString());
    }
}