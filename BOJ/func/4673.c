#include <stdio.h>

int main(void)
{
    int flag[10001] = {0};

    for(int i = 1; i <= 10000; i++)
    {
        if(i < 10)
            flag[2 * i] = 1;
        else if(i < 100)
            flag[i + i % 10 + i / 10] = 1;
        else if(i < 1000)
            flag[i + i % 10 + ((i % 100) / 10) + i / 100] = 1;
        else
        {
            int n = i + i % 10 + ((i % 100) / 10) + ((i % 1000) / 100) + ((i % 10000) / 1000) + i / 10000;
            if(n <= 10000)
                flag[n] = 1;
            else
                continue;
        }
    }
    for(int i = 1; i <= 10000; i++)
        if(!flag[i])
            printf("%d\n", i);

    return 0;
}