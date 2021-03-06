#include <stdio.h>
#include <stdbool.h>

int result[9];
bool visited[9];

void dfs(int N, int index, int M)
{
    for(int i = 1; i <= N; i++)
        if(!visited[i])
        {
            result[index] = i;
            if(index == M)
            {
                for(int j = 1; j <= index; j++)
                    printf("%d ", result[j]);
                printf("\n");
            }
            else
            {
                visited[i] = true;
                dfs(N, index + 1, M);
                visited[i] = false;
            }
        }
}

int main(void)
{
    int N, M;

    scanf("%d %d", &N, &M);

    dfs(N, 1, M);

    return 0;
}