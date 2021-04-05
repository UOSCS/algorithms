#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

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

void binary_search(int N, int *arr, int num)
{
    for(int left = 0, right = N - 1; left <= right; )
    {
        int mid = (left + right) / 2;
        if(arr[mid] == num)
        {
            printf("1\n");
            return;
        }
        else if(arr[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("0\n");
}

int main(void)
{
    int N, M, *arr;

    scanf("%d", &N);
    arr = malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);
    scanf("%d", &M);

    merge_sort(arr, 0, N - 1);

    for(int i = 0, num; i < M; i++)
    {
        scanf("%d", &num);
        if(num > arr[N - 1] || num < arr[0])
        {
            printf("0\n");
            continue;
        }
        binary_search(N, arr, num);
    }
    free(arr);

    return 0;
}