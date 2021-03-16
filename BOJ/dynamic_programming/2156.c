#include <stdio.h>

int wine_cache[10000][3], N, arr[10000];

int wine(int depth, int succession)
{
    if(depth >= N)
        return 0;
    else
    {
        if(!wine_cache[depth][succession])
        {
            if(succession == 2)
                wine_cache[depth][succession] = wine(depth + 1, 0);
            else
            {
                int tmp1, tmp2;
                tmp1 = arr[depth] + wine(depth + 1, succession + 1);
                tmp2 = wine(depth + 1, 0);
                wine_cache[depth][succession] = (tmp1 > tmp2 ? tmp1 : tmp2);
            }
        }
        return wine_cache[depth][succession];
    }
}

int main(void)
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    printf("%d\n", wine(0, 0));

    return 0;
}