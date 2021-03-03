#include <stdio.h>

#define SIZE 8001

int main(void)
{
    int counting_sort[SIZE] = {0};
    int N, max = -4000, min = 4000, sum = 0, bias = 4000, prev;

    scanf("%d", &N);

    for(int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        counting_sort[tmp + bias]++;
        sum += tmp;
        if(tmp > max)
            max = tmp;
        if(tmp < min)
            min = tmp;
    }

    printf("%.f\n", (double)sum / N);

    for(int i = min, count = 0; i <= max; i++)
        for(int j = 0; j < counting_sort[i + bias]; j++)
            if(count++ == (N / 2))
                printf("%d\n", i);

    for(int i = max, next, threshold = 0; i >= min; i--)
        if(counting_sort[i + bias] > threshold)
        {
            next = prev = i;
            threshold = counting_sort[i + bias];
        }
        else if(counting_sort[i + bias] == threshold)
        {
            prev = next;
            next = i;
        }
    printf("%d\n", prev);

    printf("%d\n", max - min);

    return 0;
}