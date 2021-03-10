#include <stdio.h>

#define SIZE 5

void zigzag(int matrix[][SIZE])
{
    for(int i = 0, value = 1, change = 1; value <= SIZE * SIZE; i += change, value++)
    {
        matrix[i / SIZE][i % SIZE] = value;
        if(((i / SIZE) % 2 == 0 && (i % SIZE) == 4) || ((i / SIZE) % 2 == 1 && (i % SIZE) == 0))
        {
            change *= -1;
            if(change == 1)
                i += SIZE - 1;
            else
                i += SIZE + 1;
        }
    }
}

void print_matrix(int matrix[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int matrix[SIZE][SIZE];

    zigzag(matrix);

    print_matrix(matrix);

    return 0;
}