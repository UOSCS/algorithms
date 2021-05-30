#include <iostream>
#include <cstring>

using namespace std;

long long dp[100][21];
int ans, N, arr[100];

long long dfs(int idx, int sum)
{
    if(idx == N - 2)
        if(sum == ans)
            return 1;
        else
            return 0;
    if(sum < 0 || sum > 20)
        return 0;
    if(dp[idx][sum] >= 0)
        return dp[idx][sum];

    long long ret = 0;
    ret += dfs(idx + 1, sum - arr[idx + 1]);
    ret += dfs(idx + 1, sum + arr[idx + 1]);
    return dp[idx][sum] = ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N - 1; i++)
        cin >> arr[i];
    cin >> ans;

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, arr[0]);

    return 0;
}