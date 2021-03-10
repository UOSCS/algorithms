#include <stdio.h>

// Tail recursion
int hanoi_count(int n, int result)
{
    if(n == 1)
        return result;
    else
        return hanoi_count(n - 1, 2 * result + 1);
}

// Non tail recursion
// int hanoi_count(int n)
// {
//     if(n == 1)
//         return 1;
//     else
//         return 2 * hanoi_count(n - 1) + 1;
// }

void hanoi_print(int n, int from, int by, int to)
{
    if(n == 1)
        printf("%d %d\n", from, to);
    else
    {
        hanoi_print(n - 1, from, to, by);
        printf("%d %d\n", from, to);
        hanoi_print(n - 1, by, from, to);
    }
}

int main(void)
{
    int N;

    scanf("%d", &N);

    printf("%d\n", hanoi_count(N, 1));

    hanoi_print(N, 1, 2, 3);

    return 0;
}