#include <iostream>

using namespace std;

int N, dp[10][1001];

int dfs(int digit, int idx)
{
    if(dp[digit][N - idx])
        return dp[digit][N - idx];
    if(idx == N)
        return 1;

    int ret = 0;
    for(int i = digit; i < 10; i++, ret %= 10007)
        ret += dfs(i, idx + 1);
    return dp[digit][N - idx] = ret;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int answer = 0;

    cin >> N;

    for(int i = 0; i < 10; i++, answer %= 10007)
        answer += dfs(i, 1);
    
    cout << answer;

    return 0;
}