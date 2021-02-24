#include <stdio.h>

// tail recursion
int factorial(int N, int result)
{
    if(N == 0)
        return result;
    else
        return factorial(N - 1, N * result);
}

// non tail recursion

// int factorial(int N)
// {
//     if(N == 0)
//         return 1;
//     else
//         return N * factorial(N - 1);
// }

int main(void)
{
    int N;

    scanf("%d", &N);

    printf("%d\n", factorial(N, 1));

    return 0;
}