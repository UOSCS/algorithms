#include <stdio.h>

int stair_cache[300][2], arr[300], N;

int stair(int n, int succession)
{
    if(n < 0)
        return 0;
    else
    {
        if(!stair_cache[n][succession])
        {
            if(succession == 1)
                stair_cache[n][succession] = arr[n] + stair(n - 2, 0);
            else
            {
                int tmp1, tmp2;
                tmp1 = stair(n - 1, 1);
                tmp2 = stair(n - 2, 0);
                stair_cache[n][succession] = arr[n] + (tmp1 > tmp2 ? tmp1 : tmp2);
            }
        }
        return stair_cache[n][succession];
    }
}

int main(void)
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);
    
    printf("%d\n", stair(N - 1, 0));

    return 0;
}