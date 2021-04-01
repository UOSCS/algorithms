#include <stdio.h>
#include <string.h>

typedef struct
{
    int element[100001];
    int front, rear;
} Deque;

int N;

void init(Deque *d)
{
    d->front = d->rear = 0;
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
    d->front = (d->front + 1) % (N + 1);
    return d->element[d->front];
}

int pop_back(Deque *d)
{
    int tmp = d->element[d->rear];
    d->rear = (d->rear - 1 + (N + 1)) % (N + 1);
    return tmp;
}

int size(Deque *d)
{
    if(d->front > d->rear)
        return (N + 1) - (d->front - d->rear);
    else
        return d->rear - d->front;
}

int D(Deque *d, int reverse)
{
    if(empty(d))
        return 1;

    if(reverse == 1)
        pop_front(d);
    else
        pop_back(d);
    return 0;
}

void print_deque(Deque *d, int reverse)
{
    int i;
    printf("[");
    if(reverse == 1)
    {
        for(i = 1; i < size(d); i++)
            printf("%d,", d->element[(d->front + i) % (N + 1)]);
        if(!empty(d))
            printf("%d", d->element[(d->front + i) % (N + 1)]);
    }
    else
    {
        for(i = 0; i < size(d) - 1; i++)
            printf("%d,", d->element[(d->rear - i + (N + 1)) % (N + 1)]);
        if(!empty(d))
            printf("%d", d->element[(d->rear - i + (N + 1)) % (N + 1)]);
    }
    printf("]\n");
}

int main(void)
{
    Deque d;
    char p[100001];
    int T;

    scanf("%d", &T);
    for(int i = 0, flag = 0, reverse = 1; i < T; i++, reverse = 1)
    {
        init(&d);
        scanf("%100000s", p);
        scanf("%d", &N);
        getchar();
        getchar();
        for(int j = 0, tmp; j < N; j++)
        {
            scanf("%d", &tmp);
            push_back(&d, tmp);
            getchar();
        }
        getchar();
        
        for(int j = 0; j < strlen(p); j++)
        {
            if(p[j] == 'R')
                reverse *= -1;
            else
            {
                flag = D(&d, reverse);
                if(flag)
                    break;
            }
        }
        if(flag)
        {
            printf("error\n");
            flag = 0;
        }
        else
            print_deque(&d, reverse);
    }

    return 0;
}