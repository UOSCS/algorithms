#include <stdio.h>

int result[9];

void dfs(int N, int index, int M, int start)
{
    for(int i = start; i <= N; i++)
    {
        result[index] = i;
        if(index == M)
        {
            for(int j = 1; j <= index; j++)
                printf("%d ", result[j]);
            printf("\n");
        }
        else
            dfs(N, index + 1, M, i);
    }
}

int main(void)
{
    int N, M;

    scanf("%d %d", &N, &M);

    dfs(N, 1, M, 1);

    return 0;
}