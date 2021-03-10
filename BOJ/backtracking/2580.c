#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    int x;
    int y;
} Pos;

Pos zeros[81];
int sudoku[9][9], num_of_zero;

void print_sudoku(void);
void dfs(int);

int main(void)
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
        {
            scanf("%d", sudoku[i] + j);
            if(!sudoku[i][j])
            {
                zeros[num_of_zero].x = i;
                zeros[num_of_zero++].y = j;
            }
        }

    dfs(0);

    return 0;
}

void print_sudoku(void)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            printf("%d ", sudoku[i][j]);
        printf("\n");
    }

    exit(0);
}

void dfs(int depth)
{
    bool exception[10] = {false};
    int x = zeros[depth].x, y = zeros[depth].y;

    for(int i = 0; i < 9; i++)
        if(sudoku[x][i])
            exception[sudoku[x][i]] = true;
    for(int i = 0; i < 9; i++)
        if(sudoku[i][y])
            exception[sudoku[i][y]] = true;
    for(int i = 0, local_square_x = (x / 3) * 3, local_square_y = (y / 3) * 3; i < 9; i++)
        if(sudoku[local_square_x + (i / 3)][local_square_y + (i % 3)])
            exception[sudoku[local_square_x + (i / 3)][local_square_y + (i % 3)]] = true;

    for(int i = 1; i < 10; i++)
        if(!exception[i])
        {
            sudoku[x][y] = i;
            if(depth == num_of_zero - 1)
                print_sudoku();
            else
            {
                dfs(depth + 1);
                sudoku[x][y] = 0;
            }
        }
}