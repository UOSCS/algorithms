#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		gcd(b, a % b);
}

int main(void)
{
    int T, N, M, g;
    
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        g = gcd(N, M);
        printf("%d\n", N * M / g);
    }

    return 0;
}