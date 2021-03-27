#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int data[10000];
    int top;
} StackType;

void push(StackType *s, int element)
{
    s->data[++(s->top)] = element;
}

int pop(StackType *s)
{
    if(s->top == -1)
        printf("-1\n");
    else
        printf("%d\n", s->data[(s->top)--]);
}

void size(StackType *s)
{
    printf("%d\n", s->top + 1);
}

void empty(StackType *s)
{
    if(s->top == -1)
        printf("1\n");
    else
        printf("0\n");
}

void top(StackType *s)
{
    if(s->top == -1)
        printf("-1\n");
    else
        printf("%d\n", s->data[s->top]);
}

int main(void)
{
    StackType *s = malloc(sizeof(StackType));
    int N;

    s->top = -1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        char arr[6];
        scanf("%5s", arr);
        if(!strcmp(arr, "push"))
        {
            int element;
            scanf("%d", &element);
            push(s, element);
        }
        else if(!strcmp(arr, "pop"))
            pop(s);
        else if(!strcmp(arr, "size"))
            size(s);
        else if(!strcmp(arr, "empty"))
            empty(s);
        else if(!strcmp(arr, "top"))
            top(s);
    }

    return 0;
}