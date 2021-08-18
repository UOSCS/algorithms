#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[2000];
bool is_visited[2000];

int dfs(int current, int depth)
{
    if(depth > 4)
        return 1;

    int ret = 0;

    is_visited[current] = true;

    for(int i = 0; i < v[current].size(); i++)
        if(!is_visited[v[current][i]])
            ret = max(ret, dfs(v[current][i], depth + 1));

    is_visited[current] = false;

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b), v[b].push_back(a);
    }

    for(int i = 0; i < N; i++)
    {
        memset(is_visited, false, sizeof(is_visited));

        int is_possible = dfs(i, 1);

        if(is_possible)
        {
            cout << is_possible;
            return 0;
        }
    }

    cout << 0;

    return 0;
}