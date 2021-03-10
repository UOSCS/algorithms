#include <stdio.h>

int main(void)
{
    int N;
    int max = 0;
    int sum = 0;

    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
        if(arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }
    printf("%f", (sum / (float)N) * 100 / max);

    return 0;
}