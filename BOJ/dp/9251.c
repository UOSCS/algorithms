#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char arr1[1001], arr2[1001];
    int max = 0;

    scanf("%1000s%1000s", arr1, arr2);

    int cache[strlen(arr1) + 1][strlen(arr2) + 1];
    memset(cache, 0, sizeof(int) * (strlen(arr1) + 1) * (strlen(arr2) + 1));

    for(int i = 1; i <= strlen(arr1); i++)
    {
        for(int j = 1; j <= strlen(arr2); j++)
        {
            if(arr1[i - 1] == arr2[j - 1])
                cache[i][j] = cache[i - 1][j - 1] + 1;
            else
                cache[i][j] = (cache[i - 1][j] > cache[i][j - 1] ? cache[i - 1][j] : cache[i][j - 1]);
            
            if(max < cache[i][j])
                max = cache[i][j];
        }
    }
    printf("%d\n", max);

    return 0;
}