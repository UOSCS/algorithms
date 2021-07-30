#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, dp_cache[10001][14], depth[10001], is_root[10001];

int LCA(int x, int y)
{
    if(depth[x] != depth [y])
    {
        if(depth[x] > depth[y])
            swap(x, y);
        for(int i = 13; i >= 0; i--)
            if(depth[y] - depth[x] >= (1 << i))
                y = dp_cache[y][i];
    }

    if(x == y)
        return x;
    else
    {
        for(int i = 13; i >= 0; i--)
            if(dp_cache[x][i] != dp_cache[y][i])
            {
                x = dp_cache[x][i];
                y = dp_cache[y][i];
            }
        return dp_cache[x][0];
    }
}

void dfs(vector<int> tree[], int node, int dep)
{
    depth[node] = dep;
    for(int i = 0; i < tree[node].size(); i++)
    {
        dp_cache[tree[node][i]][0] = node;
        dfs(tree, tree[node][i], dep + 1);
    }
}

void dp()
{
    for(int i = 1; i < 14; i++)
        for(int j = 1; j <= N; j++)
            dp_cache[j][i] = dp_cache[dp_cache[j][i - 1]][i - 1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        vector<int> tree[10001];
        int x, y, root;
        cin >> N;
        memset(is_root, 0, sizeof(is_root));
        for(int j = 0, parent, child; j < N - 1; j++)
        {
            cin >> parent >> child;
            tree[parent].push_back(child);
            is_root[child] = 1;
        }
        for(int j = 1; j <= N; j++)
            if(!is_root[j])
            {
                root = j;
                break;
            }
        dfs(tree, root, 0);
        dp();
        cin >> x >> y;
        cout << LCA(x, y) << '\n';
    }

    return 0;
}