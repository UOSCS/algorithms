#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[10001];
int count_parent[10001], low[10001], high[10001];
int col_idx;

void dfs(int node, int level)
{
    if(arr[node].first > 0)
        dfs(arr[node].first, level + 1);
    low[level] = min(low[level], col_idx);
    high[level] = max(high[level], col_idx++);
    if(arr[node].second > 0)
        dfs(arr[node].second, level + 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, root, max_level, max_width;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int parent, child1, child2;
        cin >> parent >> child1 >> child2;
        if(child1 > 0)
        {
            count_parent[child1]++;
            arr[parent].first = child1;
        }
        if(child2 > 0)
        {
            count_parent[child2]++;
            arr[parent].second = child2;
        }
    }

    for(int i = 1; i <= N; i++)
        low[i] = 10000;
    for(int i = 1; i <= N; i++)
        if(!count_parent[i])
        {
            root = i;
            break;
        }
    col_idx = 1;
    dfs(root, 1);
    max_level = 1;
    max_width = high[1] - low[1] + 1;
    for(int i = 2; i <= N; i++)
    {
        int tmp = high[i] - low[i] + 1;
        if(max_width < tmp)
        {
            max_level = i;
            max_width = tmp;
        }
    }

    cout << max_level << ' ' << max_width << '\n';

    return 0;
}