#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 500000

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

int lower_bound(int N, int *arr, int num)
{
    for(int left = 0, right = N - 1; left <= right; )
    {
        int mid = (left + right) / 2;
        if(arr[mid] == num)
        {
            if(left == right)
                return mid;
            right = mid;
        }
        else if(arr[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int upper_bound(int N, int *arr, int num)
{
    for(int left = 0, right = N - 1; left <= right; )
    {
        int mid = (left + right + 1) / 2;
        if(arr[mid] == num)
        {
            if(left == right)
                return mid;
            left = mid;
        }
        else if(arr[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
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

    for(int i = 0, num, lb, ub; i < M; i++)
    {
        scanf("%d", &num);
        if(num > arr[N - 1] || num < arr[0])
        {
            printf("0 ");
            continue;
        }
        lb = lower_bound(N, arr, num);
        ub = upper_bound(N, arr, num);
        if(lb == -1)
            printf("0 ");
        else
            printf("%d ", ub - lb + 1);
    }

    free(arr);

    return 0;
}