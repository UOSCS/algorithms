#include <stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);

    while((N % 2) == 0)
    {
        N /= 2;
        printf("2\n");
    }
    for(int i = 3; N != 1; i += 2)
    {
        if((N % i) == 0)
        {
            N /= i;
            printf("%d\n", i);
            i -= 2;
        }
    }

    return 0;
}