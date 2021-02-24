#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int N;

void handle_flag(int n, bool flag[][N])
{   
    if(n == 1)
        return;
    else
        for(int x = n / 3; x < N; x += n)
            for(int y = n / 3; y < N; y += n)
                for(int i = 0; i < n / 3; i++)
                    for(int j = 0; j < n / 3; j++)
                        flag[x + i][y + j] = false;
    handle_flag(n / 3, flag);
}

void print_stars(bool flag[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            if(flag[i][j])
                printf("*");
            else
                printf(" ");
        printf("\n");
    }
}

int main(void)
{
    scanf("%d", &N);
    bool flag[N][N];

    memset(flag, true, sizeof(bool) * N * N);

    handle_flag(N, flag);

    print_stars(flag);

    return 0;
}