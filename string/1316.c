#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;
    int count = 0;
    char temp[101];

    scanf("%d", &N);
    char arr[N][101];
    for(int i = 0; i < N; i++)
        scanf("%s", arr[i]);

    for(int i = 0, flag = 0, index = 0; i < N; i++, flag = 0, index = 0)
    {
        temp[index] = arr[i][0];
        for(int j = 1; j < strlen(arr[i]); j++)
        {
            if(temp[index] != arr[i][j])
                for(int k = 0; k < index; k++)
                    if(temp[k] == arr[i][j])
                    {
                        flag = 1;
                        break;
                    }
            if(!flag)
                temp[++index] = arr[i][j];
            else
                break;
        }
        if(!flag)
            count++;
    }
    printf("%d", count);

    return 0;
}