#include <iostream>
int DP[31][31];

void combination(){
    for(int i = 0; i < 31; i++){
        DP[i][0] = 1;
        DP[i][i] = 1; 
        for(int j = 1; j < i; j++){ // 파스칼의 삼각형 바로 윗줄까지 안다면 구할 수 있다
            DP[i][j] = DP[i-1][j-1] + DP[i-1][j]; // 파스칼의 삼각형 값 채우기
        } 
    }
}

int main(void) {
    int T, N, M;
    scanf("%d", &T);
    combination();
    
    for(int i = 0; i < T; i++){
        scanf("%d %d", &N, &M);
        printf("%d\n", DP[M][N]); // M개중에서 N개 선택 mCn
    }

    return 0;
}