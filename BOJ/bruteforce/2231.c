#include <stdio.h>

int main(void)
{
    int N, min_of_cons;

    scanf("%d", &N);
    min_of_cons = N + 1;

    for(int i = 1; i < N; i++)
    {
        int sum_of_decom = i;
        
        for(int tmp = i; tmp; tmp /= 10)
            sum_of_decom += tmp % 10;
        
        if(sum_of_decom == N && sum_of_decom < min_of_cons)
        {
            printf("%d\n", i);

            return 0;
        }
    }

    printf("0\n");

    return 0;
}