#include <stdio.h>

typedef long long ll;

int matrix[5][5], result[5][5];

void mul_matrix(int N, int matrix_1[][5], int matrix_2[][5])
{
    int tmp[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            tmp[i][j] = 0;
            for(int k = 0; k < N; k++, tmp[i][j] %= 1000)
                tmp[i][j] += matrix_1[i][k] * matrix_2[k][j];
        }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            matrix_1[i][j] = tmp[i][j];
}

void print_matrix(int N, int matrix[][5])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int N;
    ll B;

    scanf("%d %lld", &N, &B);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", matrix[i] + j);

    for(int i = 0; i < N; i++)
        result[i][i] = 1;
    while(B > 0)
    {
        if(B & 1)
            mul_matrix(N, result, matrix);
        mul_matrix(N, matrix, matrix);
        B >>= 1;
    }
    print_matrix(N, result);

    return 0;
}