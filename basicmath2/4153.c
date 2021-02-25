#include <stdio.h>

int main(void)
{
    int arr[3], max, sum;

    while(1)
    {
        scanf("%d %d %d", arr, arr + 1, arr + 2);

        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
            break;
        else
        {
            max = sum = 0;

            for(int i = 0; i < 3; i++)
            {
                sum += arr[i] * arr[i];
                if(arr[i] > max)
                    max = arr[i];
            }
            
            if(2 * (max * max) == sum)
                printf("right\n");
            else
                printf("wrong\n");
        }
    }

    return 0;
}