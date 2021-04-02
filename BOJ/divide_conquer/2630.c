#include <stdio.h>

int arr[128][128], white, blue;

void conquer(int row, int col)
{
    if(arr[row][col] == 1)
        blue++;
    else
        white++;
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
        divide(start_row, start_col, length / 2);
        divide(start_row + length / 2, start_col, length / 2);
        divide(start_row, start_col + length / 2, length / 2);
        divide(start_row + length / 2, start_col + length / 2, length / 2);
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
    printf("%d\n%d\n", white, blue);

    return 0;
}