#include <stdio.h>
#include <stdlib.h>

int N;

typedef struct
{
    int *element;
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = 0;
}

int is_empty(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, int element)
{
    q->rear = (q->rear + 1) % (N + 1);
    q->element[q->rear] = element;
}

int dequeue(Queue *q)
{
    if(is_empty(q))
        return -1;

    q->front = (q->front + 1) % (N + 1);
    return q->element[q->front];
}

int size(Queue *q)
{
    if(q->front == q->rear)
        return 0;
    else if(q->front > q->rear)
        return (N + 1) - (q->front - q->rear);
    else
        return q->rear - q->front;
}

void front(Queue *q)
{
    printf("%d\n", is_empty(q) ? -1 : q->element[(q->front + 1) % (N + 1)]);
}

int main(void)
{
    Queue *q = malloc(sizeof(Queue));

    init(q);

    scanf("%d", &N);

    q->element = malloc(sizeof(int) * (N + 1));
    for(int i = 1; i <= N; i++)
        enqueue(q, i);
    while(size(q) != 1)
    {
        int tmp;
        dequeue(q);
        tmp = dequeue(q);
        enqueue(q, tmp);
    }
    front(q);

    return 0;
}