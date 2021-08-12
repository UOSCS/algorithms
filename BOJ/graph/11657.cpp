#include <iostream>
#include <queue>

#define INF 5000001

using namespace std;

typedef pair<pair<int, int>, int> p;

vector<p> edges;
int N, M;
long long dist[501];

void bellman_ford()
{
    fill(dist, dist + 501, INF);

    dist[1] = 0;

    for(int i = 0; i < N - 1; i++)
        for(int j = 0; j < edges.size(); j++)
        {
            int from = edges[j].first.first;
            int to = edges[j].first.second;
            int cost = edges[j].second;

            if(dist[from] == INF) continue;
            if(dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
        }

    for(int i = 0; i < edges.size(); i++)
    {
        int from = edges[i].first.first;
        int to = edges[i].first.second;
        int cost = edges[i].second;

        if(dist[from] == INF) continue;
        if(dist[to] > dist[from] + cost)
        {
            cout << -1;
            return;
        }
    }

    for(int i = 2; i <= N; i++)
        cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int A, B, C;

        cin >> A >> B >> C;

        edges.push_back({ { A, B }, C });
    }

    bellman_ford();

    return 0;
}