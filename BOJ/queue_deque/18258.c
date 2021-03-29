#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int *element;
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = -1;
}

int is_empty(Queue *q)
{
    return q->front == q->rear ? 1 : 0;
}

void push(Queue *q, int element)
{
    q->element[++(q->rear)] = element;
}

void pop(Queue *q)
{
    printf("%d\n", is_empty(q) ? -1 : q->element[++(q->front)]);
}

void size(Queue *q)
{
    printf("%d\n", q->rear - q->front);
}

void empty(Queue *q)
{
    printf("%d\n", is_empty(q) ? 1 : 0);
}

void front(Queue *q)
{
    printf("%d\n", is_empty(q) ? -1 : q->element[q->front + 1]);
}

void back(Queue *q)
{
    printf("%d\n", is_empty(q) ? -1 : q->element[q->rear]);
}

int main(void)
{
    Queue *q = malloc(sizeof(Queue));
    int N;

    init(q);

    scanf("%d", &N);

    q->element = malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
    {
        char arr[6];

        scanf("%5s", arr);

        if(!strcmp(arr, "push"))
        {
            int element;
            scanf("%d", &element);
            push(q, element);
        }
        else if(!strcmp(arr, "pop"))
            pop(q);
        else if(!strcmp(arr, "size"))
            size(q);
        else if(!strcmp(arr, "empty"))
            empty(q);
        else if(!strcmp(arr, "front"))
            front(q);
        else if(!strcmp(arr, "back"))
            back(q);
    }

    return 0;
}