#include <stdio.h>

void get_input(int *a, int *b, int matrix[][100])
{
    scanf("%d %d", a, b);
    for(int i = 0; i < *a; i++)
        for(int j = 0; j < *b; j++)
            scanf("%d", matrix[i] + j);
}

void print_matrix(int matrix[][100], int N, int K)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < K; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int N, M, K;
    int matrix_1[100][100], matrix_2[100][100], result[100][100];

    get_input(&N, &M, matrix_1);
    get_input(&M, &K, matrix_2);

    for(int i = 0; i < N; i++)
        for(int j = 0, sum = 0; j < K; j++, sum = 0)
        {
            for(int x = 0; x < M; x++)
                sum += matrix_1[i][x] * matrix_2[x][j];
            result[i][j] = sum;
        }
    print_matrix(result, N, K);

    return 0;
}