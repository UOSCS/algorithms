#include <stdio.h>

int main(void)
{
    int N, K, arr[10], count = 0;

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    for(int i = N - 1; i >= 0; i--)
    {
        if(arr[i] <= K)
        {
            count += K / arr[i];
            K %= arr[i];
        }
        if(!K)
            break;
    }
    printf("%d\n", count);

    return 0;
}