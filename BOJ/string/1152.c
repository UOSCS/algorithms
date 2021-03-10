#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[1000000];
    char *temp;
    int count = 0; 

    gets(word);

    temp = strtok(word, " ");
    while(temp != NULL)
    {
        count++;
        temp = strtok(NULL, " ");
    }
    printf("%d", count);

    return 0;
}