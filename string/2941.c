#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[101];
    char *ptr;
    char tokens[][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int count = 0;
    int flag = 0;

    scanf("%s", input);
    for(ptr = input; *ptr; count++, flag = 0)
    {
        for(int i = 0; i < (sizeof(tokens) / sizeof(tokens[0])) && !flag; i++)
        {
            if(!strncmp(tokens[i], ptr, strlen(tokens[i])))
            {
                ptr += strlen(tokens[i]);
                flag = 1;
            }
        }
        if(!flag)
            ptr++;
    }
    printf("%d", count);

    return 0;
}