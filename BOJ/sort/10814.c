#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct
{
    int age;
    char name[101];
} Member;

Member result[SIZE];

void merge(Member *arr, int left, int mid, int right)
{
    int i, j, index;

    for(i = left, j = mid + 1, index = left; i <= mid && j <= right; index++)
        if(arr[i].age <= arr[j].age)
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

void merge_sort(Member *arr, int left, int right)
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
    Member *arr;
    int N;

    scanf("%d", &N);

    arr = malloc(sizeof(Member) * N);

    for(int i = 0; i < N; i++)
        scanf("%d %100s", &arr[i].age, arr[i].name);

    merge_sort(arr, 0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d %s\n", arr[i].age, arr[i].name);

    return 0;
}