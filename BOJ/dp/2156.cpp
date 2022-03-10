//
//  main.cpp
//  cpp
//
//

#include <iostream>

using namespace std;

int N, arr[10000], dp[10001][3];

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
        
    cin >> N;
        
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    for (int i = 1; i <= N; i++) {
        dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        dp[i][1] = dp[i - 1][0] + arr[i - 1];
        dp[i][2] = dp[i - 1][1] + arr[i - 1];
    }
        
    cout << max(max(dp[N][0], dp[N][1]), dp[N][2]);;
}

