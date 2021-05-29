#include <iostream>
#include <algorithm>

using namespace std;

int N, W[17][17], dp[17][1 << 16];
int ans_bit;

int dfs(int node, int state)
{
    if(state == ans_bit)
        if(W[node][1])
            return W[node][1];
        else
            return -1;
    if(dp[node][state])
        return dp[node][state];
    
    int ret = 16000000;
    for(int i = 1; i <= N; i++)
    {
        if((1 << (i - 1)) & state)
            continue;
        if(!W[node][i])
            continue;
        int tmp = dfs(i, state | (1 << (i - 1)));
        if(tmp > 0)
            ret = min(ret, tmp + W[node][i]);
    }
    return dp[node][state] = ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> W[i][j];
    
    ans_bit = (1 << N) - 1;
    cout << dfs(1, 1) << '\n';

    return 0;
}