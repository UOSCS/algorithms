#include <stdio.h>
#include <math.h>

int main(void)
{
    int M, N, min = 10000, sum = 0;

    scanf("%d%d", &M, &N);

    for(int i = M, result = 1; i <= N; i++, result = 1)
    {
        if(i == 1)
            result = 0;
        else
            for(int j = 2; j <= sqrt(i); j++)
                if((i % j) == 0)
                {
                    result = 0;
                    break;
                }

        if(result)
        {
            sum += i;
            if(min > i)
                min = i;
        }
    }
    if(!sum)
        printf("-1\n");
    else
        printf("%d\n%d\n", sum, min);

    return 0;
}