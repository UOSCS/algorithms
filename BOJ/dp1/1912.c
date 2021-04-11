#include <stdio.h>

int main(void)
{
    int N, max = -1000;

    scanf("%d", &N);
    for(int i = 0, num, sum = 0; i < N; i++)
    {
        scanf("%d", &num);
        if(sum <= 0)
            sum = num;
        else
            sum += num;
        if(sum > max)
            max = sum;
    }
    printf("%d\n", max);

    return 0;
}