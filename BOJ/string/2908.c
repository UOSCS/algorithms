#include <stdio.h>
#include <string.h>

int main(void)
{
    char A[4], B[4];
    char *outcome;
    int result = 0;

    scanf("%3s %3s", A, B);

    for(int i = strlen(A) - 1; i >= 0; i--)
    {
        if(A[i] > B[i])
            break;
        else if(A[i] < B[i])
        {
            result = 1;
            break;
        }
        else
            continue;
    }

    outcome = result ? B : A;
    for(int i = strlen(A) - 1; i >= 0; i--)
        printf("%c", outcome[i]);

    return 0;
}