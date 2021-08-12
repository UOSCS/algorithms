#include <iostream>

#define INF 500

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M, answer = 0;
    int distance[501][501];

    fill(*distance, *distance + (sizeof(distance) >> 2), INF);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;

        distance[a][b] = 1;
    }

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                if(distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
    
    for(int i = 1; i <= N; i++)
    {
        int count = 0;

        for(int j = 1; j <= N; j++)
            if(distance[i][j] < INF)
                count++;

        for(int j = 1; j <= N; j++)
            if(distance[j][i] < INF)
                count++;

        if(count == N - 1)
            answer++;
    }

    cout << answer;

    return 0;
}