#include <stdio.h>

typedef struct 
{
    int count_zeros;
    int count_ones;
} Count;

Count fibo_cache[41];

Count fibonacci(int n)
{
    if(n == 0)
        return fibo_cache[0];
    else if(n == 1)
        return fibo_cache[1];
    else
    {
        if(!fibo_cache[n].count_zeros && !fibo_cache[n].count_ones)
        {
            Count fibo1 = fibonacci(n - 1), fibo2 = fibonacci(n - 2);

            fibo_cache[n].count_zeros = fibo1.count_zeros + fibo2.count_zeros;
            fibo_cache[n].count_ones = fibo1.count_ones + fibo2.count_ones;
        }
        return fibo_cache[n];
    }
}

int main(void)
{
    int T;

    scanf("%d", &T);

    fibo_cache[0].count_zeros = 1;
    fibo_cache[1].count_ones = 1;

    for(int i = 0, N; i < T; i++)
    {
        Count count;

        scanf("%d", &N);

        count = fibonacci(N);

        printf("%d %d\n", count.count_zeros, count.count_ones);
    }

    return 0;
}