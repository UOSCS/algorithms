#include <iostream>
#include <cstring>

using namespace std;

int N, dp[100][10][1 << 10];

int dfs(int i, int d, int mask)
{
    if(i == N - 1)
    {
        if(mask == (1 << 10) - 1)
            return dp[i][d][mask] = 1;
        else
            return dp[i][d][mask] = 0;
    }
    if(dp[i][d][mask] >= 0)
        return dp[i][d][mask];

    dp[i][d][mask] = 0;
    if(d - 1 >= 0)
        dp[i][d][mask] += dfs(i + 1, d - 1, mask | (1 << (d - 1)));
    if(d + 1 < 10)
        dp[i][d][mask] += dfs(i + 1, d + 1, mask | (1 << (d + 1)));
    return dp[i][d][mask] %= 1000000000;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int result = 0;

    cin >> N;

    memset(dp, -1, sizeof(dp));
    for(int i = 1; i < 10; i++, result %= 1000000000)
        result += dfs(0, i, 1 << i);

    cout << result;

    return 0;
}