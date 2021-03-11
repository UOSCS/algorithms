#include <stdio.h>

int main(void)
{
    int N, f;

    scanf("%d", &N);

    if(N == 1)
        f = 1;
    else if(N == 2)
        f = 2;
    else
        for(int i = 3, f1 = 2, f2 = 1; i <= N; i++)
        {
            f = (f1 + f2) % 15746;
            f2 = f1;
            f1 = f;
        }
    printf("%d\n", f);

    return 0;
}