#include <stdio.h>

int main(void)
{
    for(int x, y; ; )
    {
        scanf("%d %d", &x, &y);
        if(!x && !y)
            break;

        if(!(y % x))
            printf("factor\n");
        else if(!(x % y))
            printf("multiple\n");
        else
            printf("neither\n");
    }

    return 0;
}