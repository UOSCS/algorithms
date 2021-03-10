#include <stdio.h>

int result[8];

void dfs(int N, int index, int M)
{
    for(int i = 1; i <= N; i++)
    {
        result[index] = i;
        if(index == M)
        {
            for(int j = 1; j <= index; j++)
                printf("%d ", result[j]);
            printf("\n");
        }
        else
            dfs(N, index + 1, M);
    }
}

int main(void)
{
    int N, M;

    scanf("%d %d", &N, &M);

    dfs(N, 1, M);

    return 0;
}