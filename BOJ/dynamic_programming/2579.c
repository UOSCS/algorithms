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
            if(succession == 2)
                stair_cache[n][2] = arr[n] + stair(n - 2, 1);
            else
            {
                int tmp1, tmp2;
                tmp1 = stair(n - 1, 2);
                tmp2 = stair(n - 2, 1);
                stair_cache[n][1] = arr[n] + (tmp1 > tmp2 ? tmp1 : tmp2);
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
    
    printf("%d\n", stair(N - 1, 1));

    return 0;
}