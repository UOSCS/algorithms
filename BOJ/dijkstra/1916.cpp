#include <iostream>
#include <queue>

#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int N, M, d[1001];
vector<pii> g[1001];

void dijkstra(int start)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    d[start] = 0;
    pq.push({ 0, start });
    while(!pq.empty())
    {
        int current = pq.top().second;
        int dist = pq.top().first;

        pq.pop();
        if(d[current] < dist) continue;
        for(int i = 0; i < g[current].size(); i++)
        {
            int next = g[current][i].second;
            int next_dist = dist + g[current][i].first;
            if(d[next] > next_dist)
            {
                d[next] = next_dist;
                pq.push({ next_dist, next });
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dep, dest;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ w, v });
    }
    cin >> dep >> dest;

    fill(d, d + 1001, INF);
    dijkstra(dep);

    cout << d[dest];

    return 0;
}