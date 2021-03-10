#include <stdio.h>

int main(void)
{
    int n = 9;
    int arr[n];
    int max = 0;
    int index = -1;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);

        if(arr[i] > max)
        {
            max = arr[i];
            index = i + 1;
        }
    }
    printf("%d\n%d", arr[index - 1], index);

    return 0;
}