#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int *element;
    int front, rear;
} Deque;

int N;

void init(Deque *d)
{
    d->front = d->rear = 0;
}

void push_front(Deque *d, int n)
{
    d->element[d->front] = n;
    d->front = (d->front - 1 + (N + 1)) % (N + 1);
}

void push_back(Deque *d, int n)
{
    d->rear = (d->rear + 1) % (N + 1);
    d->element[d->rear] = n;
}

int empty(Deque *d)
{
    return d->front == d->rear ? 1 : 0;
}

void pop_front(Deque *d)
{
    if(empty(d))
        printf("-1\n");
    else
    {
        d->front = (d->front + 1) % (N + 1);
        printf("%d\n", d->element[d->front]);
    }
}

void pop_back(Deque *d)
{
    if(empty(d))
        printf("-1\n");
    else
    {
        printf("%d\n", d->element[d->rear]);
        d->rear = (d->rear - 1 + (N + 1)) % (N + 1);
    }
}

void size(Deque *d)
{
    if(d->front > d->rear)
        printf("%d\n", (N + 1) - (d->front - d->rear));
    else
        printf("%d\n", d->rear - d->front);
}

void front(Deque *d)
{
    printf("%d\n", empty(d) ? -1 : d->element[(d->front + 1) % (N + 1)]);
}

void back(Deque *d)
{
    printf("%d\n", empty(d) ? -1 : d->element[d->rear]);
}

int main(void)
{
    Deque *d = malloc(sizeof(Deque));

    init(d);
    scanf("%d", &N);
    d->element = malloc(sizeof(int) * (N + 1));
    
    for(int i = 0; i < N; i++)
    {
        char arr[11];
        scanf("%10s", arr);
        if(!strcmp(arr, "push_front"))
        {
            int num;
            scanf("%d", &num);
            push_front(d, num);
        }
        else if(!strcmp(arr, "push_back"))
        {
            int num;
            scanf("%d", &num);
            push_back(d, num);
        }
        else if(!strcmp(arr, "pop_front"))
            pop_front(d);
        else if(!strcmp(arr, "pop_back"))
            pop_back(d);
        else if(!strcmp(arr, "size"))
            size(d);
        else if(!strcmp(arr, "empty"))
            printf("%d\n", empty(d));
        else if(!strcmp(arr, "front"))
            front(d);
        else if(!strcmp(arr, "back"))
            back(d);
    }

    return 0;
}