#include <iostream>

using namespace std;

long dp[91];

int main(void)
{
    ios::sync_with_stdio(0);

    int n;

    cin >> n;

    dp[0] = 0, dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    cout << dp[n];

    return 0;
}