#include <iostream>
#include <cstring>

using namespace std;

int dp[11], ds[] = {1, 2, 3};

int dfs(int n, int sum)
{
    if(sum > n)
        return 0;
    if(dp[sum] >= 0)
        return dp[sum];
    if(n == sum)
        return 1;

    dp[sum] = 0;
    for(int i = 0; i < 3; i++)
        dp[sum] += dfs(n, sum + ds[i]);
    return dp[sum];
}

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << dfs(n, 0) << '\n';
    }

    return 0;
}