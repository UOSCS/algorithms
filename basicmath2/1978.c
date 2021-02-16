#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, count = 0;

    scanf("%d" ,&N);
    
    for(int i = 0, result = 1, num; i < N; i++, result = 1)
    {
        scanf("%d", &num);

        if(num == 1)
            result = 0;
        else
            for(int j = 2; j <= sqrt(num); j++)
                if((num % j) == 0)
                {
                    result = 0;
                    break;
                }
        
        if(result)
            count++;
    }
    printf("%d", count);

    return 0;
}