#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char data[100];
    int top;
} StackType;

void push(StackType *s, char element)
{
    s->data[(s->top)++] = element;
}

char pop(StackType *s)
{
    if(!(s->top))
        return '\0';
    return s->data[--(s->top)];
}

int main(void)
{
    StackType *s = malloc(sizeof(StackType));
    
    while(1)
    {
        char arr[102];
        int flag = 1;

        s->top = 0;

        fgets(arr, 102, stdin);

        if(!strcmp(arr, ".\n"))
            break;

        for(int i = 0; i < strlen(arr); i++)
        {
            if(arr[i] == '(' || arr[i] == '[')
                push(s, arr[i]);
            else if(arr[i] == ')' || arr[i] == ']')
            {
                char c = pop(s);
                if(c == '\0' || (!(arr[i] == ')' && c == '(') && !(arr[i] == ']' && c == '[')))
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag && !(s->top))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}