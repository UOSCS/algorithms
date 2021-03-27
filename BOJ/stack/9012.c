#include <stdio.h>
#include <string.h>

int main(void)
{
    int T;

    scanf("%d", &T);
    for(int i = 0, top; i < T; i++)
    {
        char arr[51];
        top = 0;
        scanf("%50s", arr);
        for(int i = 0; i < strlen(arr); i++)
        {
            if(arr[i] == '(')
                top++;
            else if(arr[i] == ')')
                top--;

            if(top < 0)
                break;
        }
        if(!top)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}