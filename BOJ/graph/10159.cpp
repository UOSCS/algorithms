#include <iostream>

#define INF 100

using namespace std;

int matrix[101][101];

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;

    fill(*matrix, *matrix + (sizeof(matrix) >> 2), INF);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;

        matrix[a][b] = 1;
    }

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                if(matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];

    for(int i = 1; i <= N; i++)
    {
        int count = 0;

        for(int j = 1; j <= N; j++)
            if(i != j && matrix[i][j] == INF && matrix[j][i] == INF)
                count++;
        
        cout << count << '\n';
    }

    return 0;
}