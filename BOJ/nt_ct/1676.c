#include <stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);
    printf("%d\n", N / 5 + N / 25 + N / 125);

    return 0;
}