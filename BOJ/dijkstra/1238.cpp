#include <iostream>
#include <queue>

#define INF 100000

using namespace std;

typedef pair<int, int> pii;

vector<pii> ori[1001], rev[1001];
int N, M, X, arr[1001];

void dijkstra(vector<pii> g[])
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int d[1001];

    fill(d, d + 1001, INF);
    d[X] = 0;
    pq.push({ 0, X });
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
    for(int i = 1; i <= N; i++)
        arr[i] += d[i];
}

int main(void)
{
    ios::sync_with_stdio(0);

    int ret = 0;

    cin >> N >> M >> X;
    for(int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ori[u].push_back({ w, v });
        rev[v].push_back({ w, u });
    }

    dijkstra(ori);
    dijkstra(rev);
    for(int i = 1; i <= N; i++)
        ret = max(ret, arr[i]);

    cout << ret;

    return 0;
}