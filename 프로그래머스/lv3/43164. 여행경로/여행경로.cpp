#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

vector<pair<string, bool>> myMap[10000];
map<string, int> m;
int dest_length;
queue<vector<string>> pq;

vector<string> v;

bool cmp(pair<string, bool> a, pair<string, bool> b)
{
    if(a.first < b.first) return true;
    else return false;
}

void dfs(string start, int idx)
{
    if(idx==dest_length)
    {
        pq.push(v);
    }
    else
    {
        if(m.find(start)==m.end()) return;
        int cur = m[start];
        for(int i=0;i<myMap[cur].size();i++)
        {
            if(!myMap[cur][i].second)
            {
                myMap[cur][i].second = true;
                v[idx]=myMap[cur][i].first;
                dfs(myMap[cur][i].first, idx+1);
                myMap[cur][i].second = false;
                
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    v.resize(tickets.size()+1);
    
    for(int i=0;i<tickets.size()+1;i++)
    {
        v[i]="";
    }
    
    dest_length = tickets.size()+1;
    for(int i=0;i<tickets.size();i++)
    {
        m.insert({tickets[i][0], i});
        myMap[m[tickets[i][0]]].push_back({tickets[i][1], false});
    }
    
    for(int i=0;i<tickets.size();i++)
    {
        sort(myMap[i].begin(), myMap[i].end(), cmp);
    }
    
    v[0]="ICN";
    dfs("ICN", 1);

    vector<string> answer;
    return pq.front();
}