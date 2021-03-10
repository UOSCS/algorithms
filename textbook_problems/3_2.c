#include <stdio.h>
#include <stdlib.h>

int N, M, my_index = -1, value = 1;

void spiral(int **matrix, int n, int m)
{
    for(int i = 0; i < m; i++)
        matrix[++my_index / M][my_index % M] = value++;
    for(int i = 0; i < n - 1; i++)
    {
        my_index += M;
        matrix[my_index / M][my_index % M] = value++;
    }
    for(int i = 0; i < m - 1; i++)
        if(n != 1)
            matrix[--my_index / M][my_index % M] = value++;
    for(int i = 0; i < n - 2; i++)
    {
        if(m != 1)
        {
            my_index -= M;
            matrix[my_index / M][my_index % M] = value++;
        }
    }
    
    if(value < N * M)
        spiral(matrix, n - 2, m - 2);
}

void print_matrix(int **matrix)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int **matrix;

    scanf("%d%d", &N, &M);

    matrix = (int **)malloc(sizeof(int *) * N);
    for(int i = 0; i < N; i++)
        matrix[i] = malloc(sizeof(int) * M);

    spiral(matrix, N, M);

    print_matrix(matrix);

    return 0;
}