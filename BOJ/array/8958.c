#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int N;

    scanf("%d", &N);
    char *arr[N];

    for(int i = 0; i < N; i++)
    {
        arr[i] = malloc(81 * sizeof(char));
        scanf("%80s", arr[i]);
    }
    
    for(int i = 0, result = 0, accumulation = 0; i < N; i++, result = accumulation = 0)
    {
        arr[i][80] = '\0';
        for(int j = 0; j < strlen(arr[i]); j++)
        {
            if(arr[i][j] == 'O')
            {
                accumulation += 1;
                result += accumulation;
            }
            else
                accumulation = 0;
        }
        printf("%d\n", result);
    }
    
    return 0;
}