#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<pii> g[1001];
vector<int> trace[1001];
int d[1001];

int dijkstra(int start, int end)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    d[start] = 0;
    trace[start].push_back(start);
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
                trace[next] = trace[current];
                trace[next].push_back(next);
                pq.push({ next_dist, next });
            }
        }
    }

    return d[end];
}

int main(void)
{
    ios::sync_with_stdio(0);

    int n, m, start, end;

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;
        g[v1].push_back({ dist, v2 });
    }
    cin >> start >> end;

    fill(d, d + 1001, 100000000);

    cout << dijkstra(start, end) << '\n';
    cout << trace[end].size() << '\n';
    for(int i : trace[end])
        cout << i << ' ';

    return 0;
}