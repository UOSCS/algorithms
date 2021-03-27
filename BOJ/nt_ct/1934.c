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
    int T;
    
    scanf("%d", &T);
    for(int i = 0, N, M, g; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        g = gcd(N, M);
        printf("%d\n", N * M / g);
    }

    return 0;
}