#include <stdio.h>

#define SIZE 100000

typedef struct
{
    int data[SIZE];
    int top;
} Stack;

int main(void)
{
    Stack s;
    int n, arr[SIZE];
    char result[SIZE * 2];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);

    s.top = -1;
    for(int i = 0, result_index = 0, sequence = 1; i < n; i++)
    {
        while(s.top == -1 || arr[i] > s.data[s.top])
        {
            result[result_index++] = '+';
            s.data[++(s.top)] = sequence++;
        }
        if(s.top != -1 && arr[i] == s.data[s.top])
        {
            result[result_index++] = '-';
            (s.top)--;
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }
    for(int i = 0; i < 2 * n; i++)
        printf("%c\n", result[i]);

    return 0;
}