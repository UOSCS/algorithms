#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, pair<int, int>> KS;

vector<KS> k;
int p[10001];

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
    cin.tie(0);

    int V, E, weight = 0;

    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        k.push_back({ cost, { v1, v2 } });
    }

    memset(p, -1, sizeof(p));
    sort(k.begin(), k.end());
    for(int i = 0, count = 0; i < E; i++)
    {
        KS ks = k[i];
        if(merge(ks.second.first, ks.second.second))
            weight += ks.first;
    }

    cout << weight;

    return 0;
}