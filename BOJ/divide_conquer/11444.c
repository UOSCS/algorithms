#include <stdio.h>

#define DIVISOR 1000000007

typedef long long ll;

void mul_matrix(ll matrix_1[][2], ll matrix_2[][2])
{
    ll tmp[2][2];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        {
            tmp[i][j] = 0;
            for(int k = 0; k < 2; k++, tmp[i][j] %= DIVISOR)
                tmp[i][j] += matrix_1[i][k] * matrix_2[k][j];
        }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            matrix_1[i][j] = tmp[i][j];
}

int main(void)
{
    ll N, matrix[2][2], result[2][2];

    scanf("%lld", &N);

    matrix[0][0] = 1; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;
    result[0][0] = 1; result[0][1] = 0;
    result[1][0] = 0; result[1][1] = 1;

    while(N > 0)
    {
        if(N & 1)
            mul_matrix(result, matrix);
        mul_matrix(matrix, matrix);
        N >>= 1;
    }
    printf("%lld\n", result[0][1]);

    return 0;
}