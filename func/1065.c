#include <stdio.h>

int main(void)
{
    int N;
    int count = 0;
    int arr[4];

    scanf("%d", &N);

    for(int i = 1, index = 0, prev = 0; i <= N; i++, prev = index = 0)
    {
        if(i < 100)
            count++;
        else
        {
            for(int j = i; j != 0; j /= 10)
            arr[index++] = j % 10;

            for(int k = 0; k < index - 1; k++)
                if((k == 0) || ((arr[k] - arr[k + 1]) == prev))
                    if(k == index - 2)
                        count++;
                    else
                    {
                        prev = arr[k] - arr[k + 1];
                        continue;
                    }
                else
                    break;
        }
    }
    printf("%d", count);

    return 0;
}