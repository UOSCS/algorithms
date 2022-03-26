//
//  main.cpp
//  cpp
//
//

#include <iostream>

#define INF 100000

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
        
    int n, k;
    
    cin >> n >> k;
    
    int arr[101];
    
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
        
    int dp[10001] = {0};
    
    fill(dp + 1, dp + k + 1, INF);
    
    for (int i = 1; i <= n; i++)
        for (int j = arr[i]; j <= k; j++)
            dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
    
    if (dp[k] == INF)
        cout << -1;
    else
        cout << dp[k];
    
    return 0;
}

