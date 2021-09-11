#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N, **arr, *rank;

    scanf("%d", &N);

    arr = (int **)malloc(sizeof(int *) * N);
    for(int i = 0; i < N; i++)
        arr[i] = malloc(sizeof(int) * 2);
    rank = malloc(sizeof(int) * N);
    memset(rank, 0, sizeof(int) * N);

    for(int i = 0; i < N; i++)
        scanf("%d %d", arr[i], arr[i] + 1);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            if(arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1])
                rank[i]++;
        
        printf("%d ", rank[i] + 1);
    }

    return 0;
}