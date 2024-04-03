#include <string>
#include <vector>
#include <iostream>
#define INT_MAX 10000000000

using namespace std;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    vector<vector<long>> dist(n+1, vector<long>(n+1, INT_MAX));
    
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    
    for(int i=0;i<fares.size();i++){
        vector<int> cur = fares[i];
        
        dist[cur[0]][cur[1]]=cur[2];
        dist[cur[1]][cur[0]]=cur[2];
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dist[j][i]!=INT_MAX && dist[i][k]!=INT_MAX && dist[j][k]>dist[j][i]+dist[i][k]){
                    dist[j][k]=dist[j][i]+dist[i][k];
                }
            }
        }
    }
    
    long answer = dist[s][a]+dist[s][b];

    for(int i=1;i<=n;i++){
        long together = dist[s][i]+dist[i][a]+dist[i][b];
        answer = min(answer, together);
    }

    return answer;

}