#include <stdio.h>

int main(void)
{
    int N, arr[1000], uphill[1000], downhill[1000], max = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    for(int i = 0, threshold = 0; i < N; i++, threshold = 0)
    {
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i])
                if(threshold < uphill[j])
                    threshold = uphill[j];
        uphill[i] = ++threshold;
    }
    for(int i = N - 1, threshold = 0; i >= 0; i--, threshold = 0)
    {
        for(int j = N - 1; j > i; j--)
            if(arr[j] < arr[i])
                if(threshold < downhill[j])
                    threshold = downhill[j];
        downhill[i] = ++threshold;
    }
    for(int i = 0; i < N; i++)
        if(max < uphill[i] + downhill[i])
            max = uphill[i] + downhill[i];
    printf("%d\n", max - 1);

    return 0;
}