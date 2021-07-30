#include <iostream>
#include <vector>

using namespace std;

int N, depth[40001], dist[40001], dp_cache[40001][17];
vector<pair<int, int>> tree[40001];

int LCA(int x, int y)
{
    if(depth[x] != depth[y])
    {
        if(depth[x] > depth[y])
            swap(x, y);
        for(int i = 15; i >= 0; i--)
            if(depth[y] - depth[x] >= (1 << i))
                y = dp_cache[y][i];
    }

    if(x == y)
        return x;

    for(int i = 15; i >= 0; i--)
        if(dp_cache[x][i] != dp_cache[y][i])
        {
            x = dp_cache[x][i];
            y = dp_cache[y][i];
        }
    return dp_cache[x][0];
}

void dfs(int node, int dep, int parent)
{
    depth[node] = dep;
    for(int i = 0; i < tree[node].size(); i++)
    {
        int &t = tree[node][i].first;
        if(t != parent)
        {
            dist[t] = dist[node] + tree[node][i].second;
            dp_cache[t][0] = node;
            dfs(t, dep + 1, node);
        }
    }
}

void dp()
{
    for(int i = 1; i < 16; i++)
        for(int j = 1; j <= N; j++)
            dp_cache[j][i] = dp_cache[dp_cache[j][i - 1]][i - 1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M;

    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int tmp1, tmp2, dist;
        cin >> tmp1 >> tmp2 >> dist;
        tree[tmp1].push_back({ tmp2, dist }); tree[tmp2].push_back({ tmp1, dist });
    }

    dfs(1, 0, 0);
    dp();
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int tmp1, tmp2, lca;
        cin >> tmp1 >> tmp2;
        lca = LCA(tmp1, tmp2);
        cout << dist[tmp1] + dist[tmp2] - (dist[lca] << 1) << '\n';
    }

    return 0;
}