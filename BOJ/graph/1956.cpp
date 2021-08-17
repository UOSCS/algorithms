#include <iostream>

#define INF 8000000

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int V, E, min_cycle = INF;
    int matrix[401][401];

    fill(*matrix, *matrix + (sizeof(matrix) >> 2), INF);

    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        matrix[a][b] = c;
    }

    for(int k = 1; k <= V; k++)
        for(int i = 1; i <= V; i++)
            for(int j = 1; j <= V; j++)
                if(matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];

    for(int i = 1; i <= V; i++)
        min_cycle = min(min_cycle, matrix[i][i]);

    if(min_cycle == INF)
        cout << -1;
    else
        cout << min_cycle;

    return 0;
}