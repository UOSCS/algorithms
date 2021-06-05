#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int prim(vector<pii> g[])
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int weight = 0;
    bool visited[200000] = {false};

    visited[0] = true;
    for(int i = 0; i < g[0].size(); i++)
        pq.push({ g[0][i] });
    
    while(pq.size())
    {
        pii tmp = pq.top();
        int node = tmp.second;

        pq.pop();
        if(!visited[node])
        {
            visited[node] = true;
            weight += tmp.first;
            for(int i = 0; i < g[node].size(); i++)
                if(!visited[g[node][i].second])
                    pq.push({ g[node][i ]});
        }
    }

    return weight;
}

int main(void)
{
    ios::sync_with_stdio(0);

    while(1)
    {
        vector<pii> g[200000];
        int total = 0, weight;
        int m, n;

        cin >> m >> n;
        if(!m && !n)
            break;

        for(int i = 0; i < n; i++)
        {
            int v1, v2, dist;
            cin >> v1 >> v2 >> dist;
            total += dist;
            g[v1].push_back({ dist, v2 }); g[v2].push_back({ dist, v1 });
        }

        weight = prim(g);

        cout << total - weight << '\n';
    }

    return 0;
}