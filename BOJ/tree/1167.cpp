#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> v[100001];
int is_visited[100001], result, end_point;

void dfs(int node, int length)
{
    if(is_visited[node])
        return;
    if(length > result)
    {
        end_point = node;
        result = length;
    }
    is_visited[node] = 1;
    for(int i = 0; i < v[node].size(); i++)
        dfs(v[node][i].first, length + v[node][i].second);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V;

    cin >> V;
    for(int i = 1; i <= V; i++)
    {
        int node, neighbor, weight;
        cin >> node >> neighbor;
        while(neighbor != -1)
        {
            cin >> weight;
            v[node].push_back({ neighbor, weight });
            cin >> neighbor;
        }
    }

    dfs(1, 0);
    memset(is_visited, 0, sizeof(is_visited));
    dfs(end_point, 0);

    cout << result << '\n';

    return 0;
}