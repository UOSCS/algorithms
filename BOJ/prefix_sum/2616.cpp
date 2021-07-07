#include <iostream>
#include <cstring>

using namespace std;

int N, n, arr[50001], dp[50001][3];

int dfs(int start, int extra)
{
    if(start + n > N + 1 || extra < 0)
        return 0;
    if(dp[start][extra] >= 0)
        return dp[start][extra];

    dp[start][extra] = max(dfs(start + 1, extra), dfs(start + n, extra - 1) + (arr[start + n - 1] - arr[start - 1]));

    return dp[start][extra];
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] + arr[i - 1];
    }
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << dfs(1, 2);

    return 0;
}