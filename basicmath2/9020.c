#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int T;
    int *arr;
    bool is_prime[10001] = {false};

    scanf("%d", &T);
    arr = malloc(sizeof(int) * T);

    for(int i = 0; i < T; i++)
        scanf("%d", arr + i);

    is_prime[0] = is_prime[1] = true;
    for(int i = 2; i * i <= 10000; i++)
        if(!is_prime[i])
            for(int j = i * i; j <= 10000; j += i)
                is_prime[j] = true;

    for(int i = 0; i < T; i++)
        for(int j = arr[i] / 2; j > 1; j--)
            if(!is_prime[j] && !is_prime[arr[i] - j])
            {
                printf("%d %d\n", j, arr[i] - j);
                break;
            }

    return 0;
}