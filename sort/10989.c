#include <stdio.h>

int main(void)
{
    int count[10001] = {0};
    int N, max = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int tmp;

        scanf("%d", &tmp);
        count[tmp]++;
        if(tmp > max)
            max = tmp;
    }

    for(int i = 0; i <= max; i++)
        for(int j = 0; j < count[i]; j++)
            printf("%d\n", i);

    return 0;
}