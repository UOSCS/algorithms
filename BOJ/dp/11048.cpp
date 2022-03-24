//
//  main.cpp
//  cpp
//
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    int N, M;
    
    cin >> N >> M;
    
    int mat[1001][1001] = {0, };
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> mat[i][j];
    
    int dp[1001][1001] = {0, };
        
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mat[i][j];
    
    cout << dp[N][M];
    
    return 0;
}

