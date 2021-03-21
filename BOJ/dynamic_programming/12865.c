#include <stdio.h>
#include <string.h>

typedef struct
{
    int W;
    int V;
} Thing;

int main(void)
{
    int N, K;
    Thing things[101];

    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
        scanf("%d %d", &things[i].W, &things[i].V);
    
    int DP[N + 1][K + 1];
    memset(DP, 0, sizeof(int) * (N + 1) * (K + 1));
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= K; j++)
            if(things[i].W > j)
                DP[i][j] = DP[i - 1][j];
            else
                if((things[i].V + DP[i - 1][j - things[i].W]) > DP[i - 1][j])
                    DP[i][j] = things[i].V + DP[i - 1][j - things[i].W];
                else
                    DP[i][j] = DP[i - 1][j];
    printf("%d\n", DP[N][K]);

    return 0;
}