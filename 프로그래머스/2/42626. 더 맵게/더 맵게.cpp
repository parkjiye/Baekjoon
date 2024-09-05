#include <string>
#include <vector>
#include <queue>
// 모든 음식의 스코빌 지수를 k이상으로
//스코빌 지수가 가장 낮은 두 개의 음식을 섞어 새로운 음식
// 가장 맵지 않은 음식의 스코빌 지수 + 두번째로 맵지않은 스코빌 지수*2

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i=0;i<scoville.size();i++)
    {
        pq.push(scoville[i]);
    }
    
    while(pq.top()<K)
    {
        if(pq.size()==1)
        {
            return -1;
        }
        
        int a = pq.top();
        pq.pop();
        
        int b = pq.top();
        pq.pop();
        
        pq.push(a+b*2);
        answer+=1;
    }
    return answer;
}