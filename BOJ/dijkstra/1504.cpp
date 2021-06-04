#include <iostream>
#include <queue>

#define INF 10000000

using namespace std;

typedef pair<int, int> pii;

int d[801];
vector<pii> g[801];

void dijkstra(int start)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    fill(d, d + 801, INF);
    d[start] = 0;
    pq.push({ 0, start });
    while(pq.size())
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

    int N, E, v1, v2;
    int t1 = 0, t2 = 0, ret;

    cin >> N >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({ c, b });
        g[b].push_back({ c, a });
    }
    cin >> v1 >> v2;

    dijkstra(1);
    t1 += d[v1]; t2 += d[v2];
    dijkstra(N);
    t1 += d[v2]; t2 += d[v1];
    dijkstra(v1);
    t1 += d[v2]; t2 += d[v2];
    if(t1 >= INF && t2 >= INF)
        ret = -1;
    else
        ret = min(t1, t2);
    cout << ret;

    return 0;
}