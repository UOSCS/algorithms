#include <stdio.h>

int DP[1001][1001];

int dp(int n, int k)
{
    if(!k)
        return 1;
    else if(k == 1)
        return n;
    else
    {
        if(!DP[n][k])
        {
            DP[n][k] += dp(n - 1, k - 1);
            if((n - 1) >= k)
                DP[n][k] += dp(n - 1, k);
            DP[n][k] %= 10007;
        }
        return DP[n][k];
    }
}

int main(void)
{
    int N, K;

    scanf("%d %d", &N, &K);

    printf("%d\n", dp(N, K));

    return 0;
}