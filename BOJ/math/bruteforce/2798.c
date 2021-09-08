#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M, max_of_sum = 0;
    int *arr;

    scanf("%d %d", &N, &M);
    arr = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    for(int i = 0; i < N - 2; i++)
        for(int j = i + 1; j < N - 1; j++)
            for(int k = j + 1; k < N; k++)
            {   
                int temp_sum = arr[i] + arr[j] + arr[k];

                if(temp_sum > max_of_sum && temp_sum <= M)
                    max_of_sum = temp_sum;
            }
    
    printf("%d\n", max_of_sum);

    return 0;
}