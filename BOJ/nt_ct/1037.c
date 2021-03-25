#include <stdio.h>

int main(void)
{
    int N, max = 2, min = 1000000;

    scanf("%d", &N);
    for(int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        if(tmp < min)
            min = tmp;
        if(tmp > max)
            max = tmp;
    }

    printf("%d\n", max * min);

    return 0;
}