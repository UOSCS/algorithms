#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, pair<int, int>> KS;

int p[1001];

int find(int node)
{
    if(p[node] < 0)
        return node;
    return p[node] = find(p[node]);
}

bool merge(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b)
        return false;
    p[a] = b;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M, K, weight = 0, count = 0;
    vector<int> core;
    vector<KS> g;

    cin >> N >> M >> K;
    for(int i = 0, tmp; i < K; i++)
    {
        cin >> tmp;
        core.push_back(tmp);
    }
    for(int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({ w, { u, v } });
    }
    
    memset(p, -1, sizeof(p));
    sort(g.begin(), g.end());
    for(int i = 0; i < core.size() - 1; i++)
        merge(core[i], core[i + 1]);
    for(int i = 0; i < g.size(); i++)
    {
        int v1 = g[i].second.first, v2 = g[i].second.second;
        if(merge(v1, v2))
            weight += g[i].first;
    }

    cout << weight;

    return 0;
}