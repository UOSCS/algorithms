#include <stdio.h>

int main(void)
{
    char operators[25];
    int i, result, operands[25];

    for(i = 0; !i || operators[i - 1] != '\n'; i++)
    {
        scanf("%d", operands + i);
        scanf("%c", operators + i);
    }

    result = operands[0];
    for(int j = 0, flag = 0; j < i - 1; j++)
    {
        if(operators[j] == '-')
            flag = 1;
        if(flag)
            result -= operands[j + 1];
        else
            result += operands[j + 1];
    }
    printf("%d\n", result);

    return 0;
}