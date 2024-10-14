#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> j;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    for(int i=0;i<jobs.size();i++)
    {
        int t = jobs[i][0];
        int c = jobs[i][1];
        
        j.push({t, c});
    }
    
    int cur_t=0;
    
    while(!j.empty() || !pq.empty())
    {
        //cout<<j.top().first<<" "<<cur_t<<"\n";
        while(!j.empty() && j.top().first<=cur_t)
        {
            pair<int, int> cur = j.top();
            j.pop();
            pq.push({cur.second, cur.first});
        }
        
        if(pq.empty()) cur_t+=1;
        else
        {
            pair<int, int> cur = pq.top();
            pq.pop();
            
            answer += (cur_t-cur.second)+cur.first;
            cur_t+=cur.first;
        }
        
        //cout<<"현재 시간: "<<cur_t<<"\n";
    }
    
    return answer/jobs.size();
}