#include <stdio.h>
#include <string.h>

int main(void)
{
    int arr[26];
    char input[100];

    memset(arr, -1, sizeof(arr));

    scanf("%s", input);

    for(int i = 0; i < strlen(input); i++)
        if(arr[input[i] - 'a'] == -1)
            arr[input[i] - 'a'] = i;

    for(int i = 0; i < 26; i++)
        printf("%d ", arr[i]);

    return 0;
}