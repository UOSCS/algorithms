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
    int N, M, g, l;
    
    scanf("%d %d", &N, &M);

    g = gcd(N, M);
    l = N * M / g;

    printf("%d\n%d\n", g, l);

    return 0;
}