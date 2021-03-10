#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    
    scanf("%d", &N);

    for(int i = 666, index = 0; ; i++)
        for(int tmp = i, count = 0; tmp; tmp /= 10)
            if((tmp % 10) == 6)
            {
                if(++count == 3)
                    if(++index == N)
                    {
                        printf("%d\n", i);
                        return 0;
                    }
            }
            else
                count = 0;

    return 0;
}