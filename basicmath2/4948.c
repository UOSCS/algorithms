#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int n, count = 0;
    bool arr[246913] = {false};

    arr[0] = arr[1] = true;

    for(int i = 2; i * i <= 246912; i++)
        if(!arr[i])
            for(int j = i * i; j <= 246912; j += i)
                arr[j] = true;

    while(1)
    {
        scanf("%d", &n);

        if(n == 0)
            break;
        else
        {   
            for(int i = n + 1; i <= 2 * n; i++)
                if(!arr[i])
                    count++;

            printf("%d\n", count);

            count = 0;
        }
    }

    return 0;
}