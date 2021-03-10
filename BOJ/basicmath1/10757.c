#include <stdio.h>
#include <string.h>

int main(void)
{
    char A[100001], B[100001];
    char result[100002];
    char *longer, *shorter;

    scanf("%100000s", A);
    scanf("%100000s", B);

    if(strlen(A) > strlen(B))
    {
        longer = A;
        shorter = B;
    }
    else
    {
        longer = B;
        shorter = A;
    }
    
    for(int i = 0, carry = 0; i <= strlen(longer); i++)
    {
        if(i < strlen(shorter))
        {
            result[i] = (shorter[strlen(shorter) - 1 - i] + longer[strlen(longer) - 1 - i] - 2 * '0' + carry) % 10 + '0';
            carry = (shorter[strlen(shorter) - 1 - i] + longer[strlen(longer) - 1 - i] - 2 * '0' + carry) / 10;
        }
        else if(i == strlen(longer))
            if(carry != 0)
                result[i] = carry + '0';
            else
                result[i] = '\0';
        else
        {
            result[i] = (longer[strlen(longer) - 1 - i] - '0' + carry) % 10 + '0';
            carry = (longer[strlen(longer) - 1 - i] - '0' + carry) / 10;
        }
    }

    for(int i = strlen(result) - 1; i >= 0; i--)
        printf("%d", result[i] - '0');

    return 0;
}