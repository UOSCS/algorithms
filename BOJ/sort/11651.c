#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct coordinate
{
    int x;
    int y;
} Coordinate;

Coordinate result[SIZE];

void merge(Coordinate *arr, int left, int mid, int right)
{
    int i, j, index;

    for(index = i = left, j = mid + 1; i <= mid && j <= right; index++)
    {
        if(arr[i].y < arr[j].y)
            result[index] = arr[i++];
        else if(arr[i].y == arr[j].y)
        {
            if(arr[i].x < arr[j].x)
                result[index] = arr[i++];
            else
                result[index] = arr[j++];
        }
        else
            result[index] = arr[j++];
    }

    if(i > mid)
        for(int k = j; k <= right; index++, k++)
            result[index] = arr[k];
    else
        for(int k = i; k <= mid; index++, k++)
            result[index] = arr[k];

    for(int k = left; k <= right; k++)
        arr[k] = result[k];
}

void merge_sort(Coordinate *arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(void)
{
    Coordinate *arr;
    int N;

    scanf("%d", &N);

    arr = malloc(sizeof(Coordinate) * N);

    for(int i = 0; i < N; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);

    merge_sort(arr, 0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);

    return 0;
}