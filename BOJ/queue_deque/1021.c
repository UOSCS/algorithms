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

int pop_front(Deque *d)
{
    if(empty(d))
        return -1;
    else
    {
        d->front = (d->front + 1) % (N + 1);
        return d->element[d->front];
    }
}

int pop_back(Deque *d)
{
    if(empty(d))
        return -1;
    else
    {
        int tmp = d->element[d->rear];
        d->rear = (d->rear - 1 + (N + 1)) % (N + 1);
        return tmp;
    }
}

int front(Deque *d)
{
    return empty(d) ? -1 : d->element[(d->front + 1) % (N + 1)];
}

int size(Deque *d)
{
    if(d->front > d->rear)
        return (N + 1) - (d->front - d->rear);
    else
        return d->rear - d->front;
}

int find_index(Deque *d, int index)
{
    for(int i = 1; i <= size(d); i++)
        if(d->element[(d->front + i) % (N + 1)] == index)
            return i;
}

int main(void)
{
    Deque *d = malloc(sizeof(Deque));
    int M, *arr, index = 0, count = 0;

    init(d);
    scanf("%d %d", &N, &M);
    d->element = malloc(sizeof(int) * (N + 1));
    arr = malloc(sizeof(int) * M);
    for(int i = 0; i < M; i++)
        scanf("%d", arr + i);

    for(int i = 1; i <= N; i++)
        push_back(d, i);
    while(index < M)
    {
        if(find_index(d, arr[index]) <= size(d) / 2 + 1)
            while(1)
            {
                int tmp = pop_front(d);
                if(tmp == arr[index])
                    break;
                else
                {
                    push_back(d, tmp);
                    count++;
                }
            }
        else
            while(1)
            {
                int tmp = front(d);
                if(tmp == arr[index])
                {
                    pop_front(d);
                    break;
                }
                else
                {
                    tmp = pop_back(d);
                    push_front(d, tmp);
                    count++;
                }
            }
        index++;
    }
    printf("%d\n", count);

    return 0;
}