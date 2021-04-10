#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int top;
} Stack;

int main(void)
{
    Stack s;
    int N, *arr, *result;

    scanf("%d", &N);
    arr = malloc(sizeof(int) * N);
    result = malloc(sizeof(int) * N);
    s.data = malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    s.top = -1;
    for(int i = N - 1; i >= 0; i--)
    {
        if(s.top == -1)
        {
            s.data[++(s.top)] = arr[i];
            result[i] = -1;
            continue;
        }
        while(arr[i] >= s.data[s.top] && s.top != -1)
            s.top--;

        if(s.top == -1)
            result[i] = -1;
        else
            result[i] = s.data[s.top];
        s.data[++(s.top)] = arr[i];
    }
    for(int i = 0; i < N; i++)
        printf("%d ", result[i]);

    free(s.data);
    
    return 0;
}