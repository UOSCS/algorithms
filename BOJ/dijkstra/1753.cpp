#include <iostream>
#include <queue>

#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int V, E, start;
int d[20001];
vector<pii> g[20001];

void dijkstra()
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

    for(int i = 1; i <= V; i++)
        if(d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V >> E >> start;
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ w, v });
    }

    for(int i = 1; i <= V; i++)
        d[i] = INF;
    dijkstra();

    return 0;
}