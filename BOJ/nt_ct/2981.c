#include <stdio.h>

int main(void)
{
    int N, arr[100], min = 1000000000, next_min = 1000000000, flag;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
        if(arr[i] < min)
        {
            next_min = min;
            min = arr[i];
        }
        else if(arr[i] < next_min)
            next_min = arr[i];
    }

    for(int i = 2; i <= min / 2; i++)
    {
        if(!(min % i))
        {
            flag = 1;
            for(int j = 0; j < N; j++)
                if(arr[j] % i)
                {
                    flag = 0;
                    break;
                }
            if(flag)
                printf("%d ", i);
        }
    }
    for(int i = min / 2 + 1; i <= min; i++)
    {
        flag = 1;
        for(int j = 0; j < N; j++)
            if((arr[j] % i) != (min - i))
            {
                flag = 0;
                break;
            }
        if(flag && i != 1)
            printf("%d ", i);
    }
    if(next_min > 2 * min)
        for(int divisor = min + 1, upper_bound = next_min - min; divisor <= upper_bound; divisor++)
            if(!(upper_bound % divisor))
            {
                flag = 1;
                for(int i = 0; i < N; i++)
                    if((arr[i] % divisor) != min)
                    {
                        flag = 0;
                        break;
                    }
                if(flag)
                    printf("%d ", divisor);
            }

    return 0;
}