#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int result[SIZE];

void merge(int arr[], int left, int mid, int right)
{
    int i, j, index;

    for(index = i = left, j = mid + 1; i <= mid && j <= right; index++)
    {
        if(arr[i] <= arr[j])
            result[index] = arr[i++];
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

void merge_sort(int arr[], int left, int right)
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
    int N, *arr;

    scanf("%d", &N);

    arr = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    merge_sort(arr, 0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);

    return 0;
}