#include <stdio.h>

int arr[2187][2187], minus_one, zero, plus_one;

void conquer(int row, int col)
{
    if(arr[row][col] == -1)
        minus_one++;
    else if(!arr[row][col])
        zero++;
    else
        plus_one++;
}

int should_divide_again(int start_row, int start_col, int length)
{
    int comparison_target = arr[start_row][start_col];
    for(int i = 0; i < length; i++)
        for(int j = 0; j < length; j++)
            if(arr[start_row + i][start_col + j] != comparison_target)
                return 1;
    return 0;
}

void divide(int start_row, int start_col, int length)
{
    if(should_divide_again(start_row, start_col, length))
    {
        divide(start_row, start_col, length / 3);
        divide(start_row, start_col + length / 3, length / 3);
        divide(start_row, start_col + 2 * length / 3, length / 3);
        divide(start_row + length / 3, start_col, length / 3);
        divide(start_row + length / 3, start_col + length / 3, length / 3);
        divide(start_row + length / 3, start_col + 2 * length / 3, length / 3);
        divide(start_row + 2 * length / 3, start_col, length / 3);
        divide(start_row + 2 * length / 3, start_col + length / 3, length / 3);
        divide(start_row + 2 * length / 3, start_col + 2 * length / 3, length / 3);
    }
    else
        conquer(start_row, start_col);
}

int main(void)
{
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", arr[i] + j);

    divide(0, 0, N);
    printf("%d\n%d\n%d\n", minus_one, zero, plus_one);

    return 0;
}