#include <stdio.h>

typedef struct line
{
    int A;
    int B;
} Line;

Line result[100];

void merge(Line *arr, int left, int mid, int right)
{
    int i, j, index;

    for(index = i = left, j = mid + 1; i <= mid && j <= right; index++)
        if(arr[i].A < arr[j].A)
            result[index] = arr[i++];
        else
            result[index] = arr[j++];
    if(i > mid)
        while(j <= right)
            result[index++] = arr[j++];
    else
        while(i <= mid)
            result[index++] = arr[i++];
    
    for(int k = left; k <= right; k++)
        arr[k] = result[k];
}

void merge_sort(Line *arr, int left, int right)
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
    Line arr[100];
    int N, cache[100], max = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &arr[i].A, &arr[i].B);
    
    merge_sort(arr, 0, N - 1);
    for(int i = 0, threshold = 0; i < N; i++, threshold = 0)
    {
        for(int j = 0; j < i; j++)
        {
            if(cache[j] > threshold)
                if(result[j].B < result[i].B)
                    threshold = cache[j];
        }
        cache[i] = ++threshold;
        if(max < cache[i])
            max = cache[i];
    }
    printf("%d\n", N - max);

    return 0;
}