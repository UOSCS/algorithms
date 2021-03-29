#include <stdio.h>

int get_product(int from, int count)
{
    int result = 1;
    for(int i = 0, start = from; i < count; i++)
        result *= start--;
    return result;
}

int main(void)
{
    int N, K;

    scanf("%d %d", &N, &K);

    printf("%d\n", get_product(N, K) / get_product(K, K));

    return 0;
}