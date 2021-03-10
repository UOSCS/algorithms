#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[1000001];
    int count[26] = {0};
    int max_index = 0;
    int flag = 0;

    scanf("%1000000s", input);

    for(int i = 0; i < strlen(input); i++)
        if((input[i] >= 'a') && (input[i] <= 'z'))
            count[input[i] - 'a']++;
        else if((input[i] >= 'A') && (input[i] <= 'Z'))
            count[input[i] - 'A']++;
    for(int i = 0; i < 26; i++)
        if(count[i] > count[max_index])
            max_index = i;
    for(int i = 0; i < 26; i++)
        if(count[max_index] == count[i])
            flag++;
    printf("%c", (flag >= 2) ? '?' : ('A' + max_index));

    return 0;
}