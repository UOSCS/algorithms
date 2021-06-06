#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

pii dijkstra(vector<pii> g[], int start)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int d[10001], n = 0, end;

    fill(d, d + 10001, 10000000);
    d[start] = 0;
    pq.push({ 0, start });
    while(pq.size())
    {
        int dist = pq.top().first;
        int current = pq.top().second;

        pq.pop();
        if(d[current] < dist) continue;
        n++;
        end = current;
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

    return { n, d[end] };
}

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        vector<pii> g[10001];
        pii tmp;
        int n, d, c;

        cin >> n >> d >> c;
        for(int j = 0; j < d; j ++)
        {
            int a, b, s;
            cin >> a >> b >> s;
            g[b].push_back({ s, a });
        }

        tmp = dijkstra(g, c);

        cout << tmp.first << ' ' << tmp.second << '\n';
    }

    return 0;
}