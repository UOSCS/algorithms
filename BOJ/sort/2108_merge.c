#include <stdio.h>
#include <stdlib.h>

#define SIZE 500001

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
    int N, max = -4000, min = 4000, sum = 0, *arr, prev;

    scanf("%d", &N);

    arr = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
        sum += arr[i];
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    merge_sort(arr, 0, N - 1);

    printf("%.f\n", (double)sum / N);

    printf("%d\n", arr[N / 2]);

    for(int i = N - 2, value = arr[N - 1], threshold = 0, count = 1, next; i >= -1; i--)
    {
        if(i != -1 && value == arr[i])
            count++;
        else
        {
            if(count > threshold)
            {
                prev = next = arr[i + 1];
                threshold = count;
            }
            else if(count == threshold)
            {
                prev = next;
                next = arr[i + 1];
            }

            if(i != -1)
            {
                count = 1; 
                value = arr[i];
            }
        }
    }
    printf("%d\n", prev);

    printf("%d\n", max - min);

    return 0;
}