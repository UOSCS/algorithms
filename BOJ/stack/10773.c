#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data[100000];
    int top;
} StackType;

void push(StackType *s, int element)
{
    s->data[++(s->top)] = element;
}

void pop(StackType *s)
{
    (s->top)--;
}

void print_sum_of_stack(StackType *s)
{
    int result = 0;
    for(int i = 0; i <= s->top; i++)
        result += s->data[i];
    printf("%d\n", result);
}

int main(void)
{
    StackType *s = malloc(sizeof(StackType));
    int K;

    s->top = -1;
    scanf("%d", &K);
    for(int i = 0, num; i < K; i++)
    {
        scanf("%d", &num);
        if(!num)
            pop(s);
        else
            push(s, num);
    }
    print_sum_of_stack(s);

    return 0;
}