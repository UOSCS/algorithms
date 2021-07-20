#include <iostream>
#include <vector>

using namespace std;

bool visited[1001];
vector<int> g[1001];

void dfs(int node)
{   
    visited[node] = true;
    for(int i = 0; i < g[node].size(); i++)
        if(!visited[g[node][i]])
            dfs(g[node][i]);
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M, ans = 0;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    for(int i = 1; i <= N; i++)
        if(!visited[i])
        {
            dfs(i);
            ans++;
        }

    cout << ans;

    return 0;
}