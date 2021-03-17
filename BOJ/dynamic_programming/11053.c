#include <stdio.h>

int main(void)
{
    int N, arr[1000], cache[1000], max = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    for(int i = 0, threshold = 0; i < N; i++, threshold = 0)
    {
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i])
                if(threshold < cache[j])
                    threshold = cache[j];
        cache[i] = threshold + 1;
        if(max < cache[i])
            max = cache[i];
    }
    printf("%d\n", max);

    return 0;
}