#include <stdio.h>

int DP[31][31];

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
        }
        return DP[n][k];
    }
}

int main(void)
{
    int T;

    scanf("%d", &T);
    for(int i = 0, N, M; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        printf("%d\n", dp(M, N));
    }

    return 0;
}