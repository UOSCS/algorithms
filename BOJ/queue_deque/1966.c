#include <stdio.h>

#define QUEUE_SIZE 101

typedef struct
{
    int priority;
    int index;
} Document;

typedef struct
{
    Document element[QUEUE_SIZE];
    int front, rear;
} Queue;


void init(Queue *q)
{
    q->front = q->rear = 0;
}

void enqueue(Queue *q, Document document)
{
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->element[q->rear] = document;
}

Document dequeue(Queue *q)
{
    q->front = (q->front + 1) % QUEUE_SIZE;
    return q->element[q->front];
}

int is_my_turn(Queue *q, Document document)
{
    if(q->front > q->rear)
    {
        for(int i = 0; i <= q->rear; i++)
            if(q->element[i].priority > document.priority)
                return 0;
        for(int i = q->front + 1; i < QUEUE_SIZE; i++)
            if(q->element[i].priority > document.priority)
                return 0;
    }
    else
    {
        for(int i = q->front + 1; i <= q->rear; i++)
            if(q->element[i].priority > document.priority)
                return 0;
    }
    return 1;
}

int main(void)
{
    int T;

    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int num_of_docu, trace_index, order = 1;
        Queue q;

        init(&q);
        scanf("%d %d", &num_of_docu, &trace_index);
        for(int j = 0; j < num_of_docu; j++)
        {
            Document document;
            scanf("%d", &document.priority);
            document.index = j;
            enqueue(&q, document);
        }
        while(1)
        {
            Document tmp = dequeue(&q);
            if(is_my_turn(&q, tmp))
                if(tmp.index == trace_index)
                    break;
                else
                    order++;
            else
                enqueue(&q, tmp);
        }
        printf("%d\n", order);
    }

    return 0;
}