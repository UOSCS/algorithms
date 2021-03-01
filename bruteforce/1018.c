#include <stdio.h>

int main(void)
{
    int M, N, min = 32;

    scanf("%d %d", &M, &N);
    char arr[M][N + 1];

    for(int i = 0; i < M; i++)
        scanf("%50s", arr[i]);

    for(int i = 0; i <= M - 8; i++)
        for(int j = 0, count1 = 0, count2 = 0; j <= N - 8; j++, count1 = count2 = 0)
        {
            for(int r = i; r < i + 8; r++)
                for(int c = j; c < j + 8; c++)
                    if((r + c) % 2 == 0)
                        if(arr[r][c] == 'W')
                            count1++;
                        else
                            count2++;
                    else
                        if(arr[r][c] == 'W')
                            count2++;
                        else
                            count1++;
            if(count1 > count2)
            {
                if(count2 < min)
                    min = count2;
            }
            else
                if(count1 < min)
                    min = count1;
        }
    printf("%d\n", min);

    return 0;
}