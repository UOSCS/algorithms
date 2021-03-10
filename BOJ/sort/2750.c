#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void selection_sort(int arr[], int n)
{
    for(int i = 0, tmp; i < n - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[min])
                min = j;

        SWAP(arr[i], arr[min], tmp);
    }
}

void insertion_sort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i], j;

        for(j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void bubble_sort(int arr[], int n)
{
    for(int i = n - 1, tmp; i > 0; i--)
        for(int j = 0; j < i; j++)
            if(arr[j] > arr[j + 1])
                SWAP(arr[j], arr[j + 1], tmp);
}

int main(void)
{
    int N, *arr;

    scanf("%d", &N);
    
    arr = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    // selection_sort(arr, N);
    // insertion_sort(arr, N);
    bubble_sort(arr, N);

    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);

    return 0;
}