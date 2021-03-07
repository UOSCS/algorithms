#include <stdio.h>

int count, N, depth;
int check[15];

int is_valid(int x, int y)
{
    for(int k = 0; k < depth; k++)
        if(y == check[k] || y == check[k] -x + k || y == check[k] + x - k)
            return 0;
    return 1;
}

void dfs()
{
    for(int i = 0; i < N; i++)
        if(is_valid(depth, i))
            if(depth == N - 1)
            {
                count++;
                return;
            }
            else
            {
                check[depth++] = i;
                dfs();
                depth--;
            }
}

int main(void)
{
    scanf("%d", &N);

    dfs();

    printf("%d\n", count);

    return 0;
}