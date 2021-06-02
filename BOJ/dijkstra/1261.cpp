#include <cstdio>
#include <queue>

#define INF 987654321

using namespace std;

typedef pair<int, pair<int, int>> pipii;

int N, M, m[100][100], d[100][100];
int dn[] = {-1, 1, 0, 0}, dm[] = {0, 0, -1, 1};

void dijkstra(int start_n, int start_m)
{
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

    d[start_n][start_m] = 0;
    pq.push({ 0, { start_n, start_m } });
    while(!pq.empty())
    {
        pair<int, int> coor = pq.top().second;
        int dist = pq.top().first;

        pq.pop();
        if(d[coor.first][coor.second] < dist) continue;
        for(int i = 0; i < 4; i++)
        {
            int next_n = coor.first + dn[i], next_m = coor.second + dm[i];
            int next_dist = dist + m[next_n][next_m];
            if(next_n >= 0 && next_n < N && next_m >= 0 && next_m < M)
                if(d[next_n][next_m] > next_dist)
                {
                    d[next_n][next_m] = next_dist;
                    pq.push({ next_dist, { next_n, next_m } });
                }
        }
    }
}

int main(void)
{
    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d", &m[i][j]);
    
    fill(*d, *d + 10000, INF);
    dijkstra(0, 0);

    printf("%d\n", d[N - 1][M - 1]);

    return 0;
}