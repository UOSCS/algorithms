#include <stdio.h>

int main(void)
{
    int N;
    int min, max;

    scanf("%d", &N);
    int arr[N];

    for(int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
        if(i == 0)
        {
            min = max = arr[i];
        }
        else
        {
            if(arr[i] > max)
                max = arr[i];
            else if(arr[i] < min)
                min = arr[i];
        }
    }
    printf("%d %d", min, max);

    return 0;
}