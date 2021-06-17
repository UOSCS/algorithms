#include <iostream>
#include <cstring>

#define DIV 1000000007

using namespace std;

typedef long long ll;

ll dp[101][101][101];

ll calc(int N, int L, int R)
{
    if(dp[N][L][R] > -1)
        return dp[N][L][R];
    if((L == 1 && R == N) || (R == 1 && L == N))
        return 1LL;
    if(!N || !L || !R)
        return 0LL;
    return dp[N][L][R] = (calc(N - 1, L, R) * (N - 2) + calc(N - 1, L - 1, R) + calc(N - 1, L, R - 1)) % DIV;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N, L, R;

    cin >> N >> L >> R;

    memset(dp, -1LL, sizeof(dp));
    cout << calc(N, L, R);

    return 0;
}