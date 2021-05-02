#include <stdio.h>

unsigned long padovan_cache[101];

unsigned long padovan(int n)
{
    if(!padovan_cache[n])
        if(n <= 3)
            padovan_cache[n] = 1;
        else if(n <= 5)
            padovan_cache[n] = 2;
        else
            padovan_cache[n] = padovan(n - 1) + padovan(n - 5);

    return padovan_cache[n];
}

int main(void)
{
    int T;

    scanf("%d", &T);
    for(int i = 0, N; i < T; i++)
    {
        scanf("%d", &N);
        printf("%lu\n", padovan(N));
    }

    return 0;
}