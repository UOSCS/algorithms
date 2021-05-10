#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> v[10001];
int is_visited[10001], end_point, diameter;

void dfs(int node, int length)
{
    if(is_visited[node])
        return;

    is_visited[node] = 1;
    if(length > diameter)
    {
        diameter = length;
        end_point = node;
    }

    for(int i = 0; i < v[node].size(); i++)
        dfs(v[node][i].first, length + v[node][i].second);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        v[parent].push_back({ child, weight });
        v[child].push_back({ parent, weight });
    }

    dfs(1, 0);
    diameter = 0;
    memset(is_visited, 0, sizeof(is_visited));
    dfs(end_point, 0);

    cout << diameter << '\n';

    return 0;
}