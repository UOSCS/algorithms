#include <stdio.h>

int result[1000];

void merge(int *P, int left, int mid, int right)
{
    int x, y, index;

    for(index = x = left, y = mid + 1; x <= mid && y <= right; index++)
        if(P[x] < P[y])
            result[index] = P[x++];
        else
            result[index] = P[y++];

    if(x > mid)
        while(y <= right)
            result[index++] = P[y++];
    else
        while(x <= mid)
            result[index++] = P[x++];

    for(int z = left; z <= right; z++)
        P[z] = result[z];
}

void merge_sort(int *P, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(P, left, mid);
        merge_sort(P, mid + 1, right);
        merge(P, left, mid, right);
    }
}

int main(void)
{
    int N, P[1000], total_sum = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", P + i);

    merge_sort(P, 0, N - 1);

    for(int i = 0, each_sum = 0; i < N; i++)
    {
        each_sum += P[i];
        total_sum += each_sum;
    }
    printf("%d\n", total_sum);

    return 0;
}