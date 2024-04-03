#include <string>
#include <vector>
#include <iostream>
#define INT_MAX 10000000000

using namespace std;

long dist[205][205];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else{
                dist[i][j]=INT_MAX;
            }
        }
    }
    
    for(int i=0;i<fares.size();i++){
        vector<int> cur = fares[i];
        
        dist[cur[0]][cur[1]]=cur[2];
        dist[cur[1]][cur[0]]=cur[2];
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dist[i][j]!=INT_MAX && dist[j][k]!=INT_MAX && dist[i][k]>dist[i][j]+dist[j][k]){
                    dist[i][k]=dist[i][j]+dist[j][k];
                }
            }
        }
    }
    
    long answer = dist[s][a]+dist[s][b];
    
    for(int i=1;i<=n;i++){
        if(i!=s){
            
            long together = dist[s][i];
            long total = together + dist[i][a]+dist[i][b];
            
            //cout<<i<<" "<<total<<"\n";
            
            if(total<answer){
                answer = total;
            }
        }
    }
    return answer;
}