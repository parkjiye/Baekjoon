#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(string s) {
    
    bool isminus=false;
    string num="";
    priority_queue<int, vector<int>> pq_less;
    priority_queue<int, vector<int>, greater<int>> pq_greater;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='-')
        {
            isminus=true;
        }
        else if(s[i]==' ')
        {
            if(isminus) 
            {
                pq_less.push(stoi(num)*(-1));
                pq_greater.push(stoi(num)*(-1));
            }
            else
            {
                pq_less.push(stoi(num));
                pq_greater.push(stoi(num));
            }
            
            isminus=false;
            num="";
        }
        else
        {
            num+=s[i];
        }
        
        if(i==s.length()-1)
        {
            if(isminus) 
            {
                pq_less.push(stoi(num)*(-1));
                pq_greater.push(stoi(num)*(-1));
            }
            else
            {
                pq_less.push(stoi(num));
                pq_greater.push(stoi(num));
            }
        }
    }
    
    
    
    cout<<pq_less.top()<<endl;
    cout<<pq_greater.top()<<endl;
    
    string answer = "";
    answer+=to_string(pq_greater.top());
    answer+=" ";
    answer+=to_string(pq_less.top());
    
    
    return answer;
}