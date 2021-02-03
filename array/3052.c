#include <stdio.h>

int main(void)
{
    int n = 10;
    int arr[n];
    int count = 0;
    int flag = 0;
    int result = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        arr[i] %= 42;
    }
    for(int i = 0; i < 42; i++)
    {
        for(int j = 0; j < n; j++)
            if(arr[j] == i)
            {
                count++;
                flag = 1;
            }
        if(flag)
        {
            result++;
            flag = 0;
        }
        if(count >= 10)
            break;
    }

    printf("%d", result);

    return 0;
}