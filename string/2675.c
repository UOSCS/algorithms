#include <stdio.h>
#include <string.h>

int main(void)
{
    int T;
    int x[1000];
    char y[1000][21];

    scanf("%d", &T);

    for(int i = 0; i < T; i++)
        scanf("%d %s", x + i, *(y + i));

    for(int i = 0; i < T; i++)
    {
        for(int j = 0; j < strlen(y[i]); j++)
            for(int k = 0; k < x[i]; k++)
                printf("%c", y[i][j]);
        printf("\n");
    }

    return 0;
}