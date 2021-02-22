#include <stdio.h>

int main(void)
{
    int arr[3][2];
    int x, y;

    for(int i = 0; i < 3; i++)
        scanf("%d %d", *(arr + i), *(arr + i) + 1);
    
    
    if(**arr == **(arr + 1))
        x = **(arr + 2);
    else if(**(arr + 1) == **(arr + 2))
        x = **arr;
    else
        x = **(arr + 1);

    if(*(*arr + 1) == *(*(arr + 1) + 1))
        y = *(*(arr + 2) + 1);
    else if(*(*(arr + 1) + 1) == *(*(arr + 2) + 1))
        y = *(*arr + 1);
    else
        y = *(*(arr + 1) + 1);

    printf("%d %d\n", x, y);

    return 0;
}