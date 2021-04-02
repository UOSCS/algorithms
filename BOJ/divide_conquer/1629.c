#include <stdio.h>

typedef unsigned long long ull;

ull _pow(ull A, ull B, ull C)
{
    if(B == 1)
        return A % C;
    else
        if(!(B % 2))
            return _pow((A * A) % C, B / 2, C);
        else
            return A * _pow((A * A) % C, (B - 1) / 2, C) % C;
}

ull main(void)
{
    ull A, B, C;

    scanf("%d%d%d", &A, &B, &C);

    printf("%d\n", _pow(A, B, C));

    return 0;
}