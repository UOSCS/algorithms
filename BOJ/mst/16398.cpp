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

    vector<KS> g;
    long long weight = 0;
    int N;

    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            int cost;
            cin >> cost;
            if(cost)
                g.push_back({ cost, { i, j } });
        }
    
    memset(p, -1, sizeof(p));
    sort(g.begin(), g.end());
    for(int i = 0; i < g.size(); i++)
    {
        KS tmp = g[i];
        if(merge(tmp.second.first, tmp.second.second))
            weight += tmp.first;
    }

    cout << weight;

    return 0;
}