#include <iostream>

#define INF 10000000

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;
    int mat[100][100];

    fill(*mat, *mat + 10000, INF);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int start, end, cost;

        cin >> start >> end >> cost;

        if(mat[start - 1][end - 1] > cost)
            mat[start - 1][end - 1] = cost;
    }

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            if(i == j || mat[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << mat[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}