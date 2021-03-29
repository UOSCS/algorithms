#include <stdio.h>

int get_gcd(int a, int b)
{
    return b == 0 ? a : get_gcd(b, a % b);
}

int main(void)
{
    int N, arr[100];

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);
    
    for(int i = 1, first_ring = arr[0], gcd; i < N; i++)
    {
        gcd = get_gcd(first_ring, arr[i]);
        printf("%d/%d\n", first_ring / gcd, arr[i] / gcd);
    }

    return 0;
}