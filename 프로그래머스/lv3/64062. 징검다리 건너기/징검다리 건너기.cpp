#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> stones, int k) {
    
    int answer = 200000000;
    deque<int> dq;
    
    for(int i=0;i<stones.size();i++)
    {
        while(dq.size()>0 && dq.back()<stones[i])
        {
            dq.pop_back();
        }
        
        dq.push_back(stones[i]);
        
        if(i>=k-1)
        {
            if(answer>dq.front()) answer = dq.front();
            if(dq.front()==stones[i-k+1]) dq.pop_front();
        }
    }
    
    return answer;
}