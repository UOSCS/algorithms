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

void enqueue(Queue *q, int element)
{
    q->rear = (q->rear + 1) % (N + 1);
    q->element[q->rear] = element;
}

int dequeue(Queue *q)
{
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
    printf("%d, ", q->element[(q->front + 1) % (N + 1)]);
}

int main(void)
{
    Queue *q = malloc(sizeof(Queue));
    int K;

    init(q);

    scanf("%d %d", &N, &K);

    q->element = malloc(sizeof(int) * (N + 1));
    for(int i = 1; i <= N; i++)
        enqueue(q, i);
    printf("<");
    while(size(q) != 1)
        for(int j = 0, tmp; j < K; j++)
            if(j < K - 1)
            {
                tmp = dequeue(q);
                enqueue(q, tmp);
            }
            else
            {
                front(q);
                dequeue(q);
            }
    printf("%d>\n", dequeue(q));

    return 0;
}