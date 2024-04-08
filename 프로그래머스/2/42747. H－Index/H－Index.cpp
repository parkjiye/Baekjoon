#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> citations) {
    map<int, int> m;
    
    sort(citations.begin(), citations.end());
    
    for(int i=0;i<citations.size();i++){
        int cur = citations[i];
        if(m.find(cur)!=m.end()){
            continue;
        }
        else{
            m.insert({cur, i+1});
        }
    }
    
    int answer = 0;
    
    for(int i=0;i<=10000;i++){
        int morethanh, lessthanh;
        auto p_m = m.lower_bound(i);
        if(p_m==m.end()){
            morethanh=0;
        }
        else{
            morethanh = citations.size()-p_m->second+1;
        }
        lessthanh = citations.size()-morethanh;
        
        if(morethanh>=i && lessthanh<=i && answer<i){
            answer = i;
        }
    }
    
    return answer;
}