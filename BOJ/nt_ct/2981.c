#include <stdio.h>
#include <stdlib.h>

int result[1000];

int get_gcd(int a, int b)
{
    return b == 0 ? a : get_gcd(b, a % b);
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, index;

    for(index = i = left, j = mid + 1; i <= mid && j <= right; index++)
    {
        if(arr[i] < arr[j])
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
    int N, arr[100], gcd, factors[1000], index = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    gcd = abs(arr[0] - arr[1]);
    for(int i = 1; i < N - 1; i++)
        gcd = get_gcd(gcd, abs(arr[i] - arr[i + 1]));
    
    for(int i = 2; i * i <= gcd; i++)
        if(!(gcd % i))
        {
            factors[index++] = i;
            if(i * i != gcd)
                factors[index++] = gcd / i;
        }

    merge_sort(factors, 0, index - 1);

    for(int i = 0; i < index; i++)
        printf("%d ", factors[i]);
    printf("%d", gcd);

    return 0;
}