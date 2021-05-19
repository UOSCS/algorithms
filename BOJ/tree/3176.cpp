#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, depth[100001], dp_cache[100001][18];
int mx[100001][18], mn[100001][18];
vector<pair<int, int>> tree[100001];

int LCA(int x, int y)
{
    if(depth[x] != depth[y])
    {
        if(depth[x] > depth[y])
            swap(x, y);
        for(int i = 16; i >= 0; i--)
            if(depth[y] - depth[x] >= (1 << i))
                y = dp_cache[y][i];
    }

    if(x == y)
        return x;
    else
    {
        for(int i = 16; i >= 0; i--)
            if(dp_cache[x][i] != dp_cache[y][i])
            {
                x = dp_cache[x][i];
                y = dp_cache[y][i];
            }
        return dp_cache[x][0];
    }
}

void dfs(int node, int dep, int parent)
{
    depth[node] = dep;
    for(int i = 0; i < tree[node].size(); i++)
    {
        pair<int, int> &t = tree[node][i];
        if(t.first != parent)
        {
            dp_cache[t.first][0] = node;
            mx[t.first][0] = mn[t.first][0] = t.second;
            dfs(t.first, dep + 1, node);
        }
    }
}

void dp()
{
    for(int i = 1; i < 17; i++)
        for(int j = 1; j <= N; j++)
        {
            dp_cache[j][i] = dp_cache[dp_cache[j][i - 1]][i - 1];
            mx[j][i] = max(mx[j][i - 1], mx[dp_cache[j][i - 1]][i - 1]);
            mn[j][i] = min(mn[j][i - 1], mn[dp_cache[j][i - 1]][i - 1]);
        }
}

pair<int, int> get_result(int lca, int x, int y)
{
    int max_result = 0, min_result = 1000000, diff;
    diff = depth[x] - depth[lca];
    for(int i = 16; i >= 0; i--)
        if(diff >= (1 << i))
        {
            max_result = max(max_result, mx[x][i]);
            min_result = min(min_result, mn[x][i]);
            x = dp_cache[x][i];
            diff -= (1 << i);
        }
    diff = depth[y] - depth[lca];
    for(int i = 16; i >= 0; i--)
        if(diff >= (1 << i))
        {
            max_result = max(max_result, mx[y][i]);
            min_result = min(min_result, mn[y][i]);
            y = dp_cache[y][i];
            diff -= (1 << i);
        }
    return { min_result, max_result };
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K;

    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int tmp1, tmp2, dist;
        cin >> tmp1 >> tmp2 >> dist;
        tree[tmp1].push_back({ tmp2, dist }); tree[tmp2].push_back({ tmp1, dist });
    }

    dfs(1, 0, 0);
    dp();
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        pair<int, int> p;
        int tmp1, tmp2, lca;
        cin >> tmp1 >> tmp2;
        lca = LCA(tmp1, tmp2);
        p = get_result(lca, tmp1, tmp2);
        cout << p.first << ' ' << p.second << '\n';
    }
}