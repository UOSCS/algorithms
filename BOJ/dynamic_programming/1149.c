#include <stdio.h>
#include <stdlib.h>

int rgb_cache[1001][3], **arr;

int rgb(int n, int prev_color)
{
    if(!rgb_cache[n][prev_color])
    {
        if(n == 1)
        {
            if(!prev_color)
                rgb_cache[n][prev_color] = (arr[n][1] > arr[n][2] ? arr[n][2] : arr[n][1]);
            else if(prev_color == 1)
                rgb_cache[n][prev_color] = (arr[n][0] > arr[n][2] ? arr[n][2] : arr[n][0]);
            else
                rgb_cache[n][prev_color] = (arr[n][0] > arr[n][1] ? arr[n][1] : arr[n][0]);
        }
        else
        {
            int min = 1000000;

            for(int i = 0, tmp; i < 3; i++)
                if(i != prev_color)
                {
                    tmp = arr[n][i] + rgb(n - 1, i);
                    if(min > tmp)
                        min = tmp;
                }
            rgb_cache[n][prev_color] = min;
        }
    }
    return rgb_cache[n][prev_color];
}

int main(void)
{
    int N, min = 1000000;

    scanf("%d", &N);

    arr = (int **)malloc(sizeof(int *) * N + 1);
    for(int i = 1; i <= N; i++)
    {
        arr[i] = malloc(sizeof(int) * 3);
        scanf("%d %d %d", arr[i], arr[i] + 1, arr[i] + 2);
    }

    for(int i = 0, tmp; i < 3; i++)
        if(min > (tmp = rgb(N, i)))
            min = tmp;
    printf("%d\n", min);

    return 0;
}