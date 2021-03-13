#include <stdio.h>

int it_cache[500][500], arr[500][500], N;

int integer_triangle(int layer, int address)
{
    if(!it_cache[layer][address])
        if(layer == N - 1)
            it_cache[layer][address] = arr[layer][address];
        else
        {
            int tmp1, tmp2, max;

            tmp1 = integer_triangle(layer + 1, address);
            tmp2 = integer_triangle(layer + 1, address + 1);
            max = (tmp1 > tmp2 ? tmp1 : tmp2);
            it_cache[layer][address] = arr[layer][address] + max;
        }
    return it_cache[layer][address];
}

int main(void)
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            scanf("%d", arr[i] + j);

    printf("%d\n", integer_triangle(0, 0));

    return 0;
}