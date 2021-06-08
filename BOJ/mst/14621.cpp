#include <iostream>
#include <vector>
#include <algorithm>
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

    vector<KS> g;
    int N, M, sex[1001], weight = 0, count = 0;

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        char tmp;
        cin >> tmp;
        if(tmp == 'M') sex[i] = 1;
        else sex[i] = 0;
    }
    for(int i = 0; i < M; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        if(sex[u] != sex[v])
            g.push_back({ d, { u, v } });
    }

    memset(p, -1, sizeof(p));
    sort(g.begin(), g.end());
    for(int i = 0; i < g.size(); i++)
    {
        KS tmp = g[i];
        if(merge(tmp.second.first, tmp.second.second))
        {
            weight += tmp.first;
            count++;
        }
    }
    
    if(count == N - 1)
        cout << weight;
    else
        cout << -1;

    return 0;
}