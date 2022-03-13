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
        
    int N;
    
    cin >> N;
    
    int arr[1001];
    
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    int dp[1001][1001] = {0, };
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (j >= i)
                dp[i][j] = max(dp[i][j - i] + arr[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
    
    cout << dp[N][N];
    
    return 0;
}

