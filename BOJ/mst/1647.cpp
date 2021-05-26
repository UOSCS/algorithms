#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> p;

vector<p> ks;
int parent[100001];

int find(int node)
{
    if(parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);
}

bool merge(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b)
        return false;
    parent[a] = b;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, total_weight = 0, last;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        ks.push_back({ cost, { v1, v2 } });
    }

    memset(parent, -1, sizeof(parent));
    sort(ks.begin(), ks.end());
    for(int i = 0; i < M; i++)
    {
        p tmp = ks[i];
        if(merge(tmp.second.first, tmp.second.second))
        {
            total_weight += tmp.first;
            last = tmp.first;
        }
    }

    cout << total_weight - last;

    return 0;
}