#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[16];
    char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *ptr;
    int time = 0;

    scanf("%s", input);
    for(int i = strlen(input) - 1; i >= 0; i--)
    {
        ptr = strchr(arr, input[i]);
        time += (ptr - arr) / 3 + 3;
        if(*ptr == 'S' || *ptr == 'V' || *ptr == 'Y' || *ptr == 'Z')
            time--;
    }
    printf("%d", time);

    return 0;
}