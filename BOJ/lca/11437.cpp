#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> edge[50001];
int depth[50001];
int dp_cache[50001][17];

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

void dp()
{
    for(int i = 1; i < 17; i++)
        for(int j = 1; j <= N; j++)
            dp_cache[j][i] = dp_cache[dp_cache[j][i - 1]][i - 1];
}

void dfs(int node, int dep, int parent)
{
    depth[node] = dep;
    for(int i = 0; i < edge[node].size(); i++)
        if(edge[node][i] != parent)
        {
            dp_cache[edge[node][i]][0] = node;
            dfs(edge[node][i], dep + 1, node);
        }
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
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }

    dfs(1, 0, 0);
    dp();

    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cout << LCA(tmp1, tmp2) << '\n';
    }

    return 0;
}