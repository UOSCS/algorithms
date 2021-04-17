#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
queue<int> q;
bool is_visited[1001];

void dfs(int node)
{
    is_visited[node] = true;
    cout << node << ' ';
    for(int i = 0; i < graph[node].size(); i++)
        if(!is_visited[graph[node][i]])
            dfs(graph[node][i]);
}

void bfs(int node)
{
    int next_node;

    is_visited[node] = true;
    cout << node << ' ';
    for(int i = 0; i < graph[node].size(); i++)
        if(!is_visited[graph[node][i]])
        {
            q.push(graph[node][i]);
            is_visited[graph[node][i]] = true;
        }
    if(!q.empty())
    {
        next_node = q.front();
        q.pop();
        bfs(next_node);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, V;

    cin >> N >> M >> V;
    for(int i = 0, node1, node2; i < M; i++)
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2); graph[node2].push_back(node1);
    }

    for(int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(V);
    fill(is_visited, is_visited + N + 1, false);
    cout << '\n';
    bfs(V);

    return 0;
}