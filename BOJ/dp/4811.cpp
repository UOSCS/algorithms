#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll dp[31][31];
int N;

ll dfs(int depth, int W, int H)
{
    if(depth == N << 1)
        return dp[W][H] = 1;
    if(dp[W][H])
        return dp[W][H];
    
    if(W > 0)
        dp[W][H] += dfs(depth + 1, W - 1, H + 1);
    if(H > 0)
        dp[W][H] += dfs(depth + 1, W, H - 1);
    return dp[W][H];
}

int main(void)
{
    ios::sync_with_stdio(0);

    while(true)
    {
        cin >> N;
        if(!N)
            break;
        memset(dp, 0, sizeof(dp));
        cout << dfs(0, N, 0) << '\n';
    }
}