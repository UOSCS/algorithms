#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> tree[10001], v;
int w[10001], dp_cache[10001][2];

int dp(int node, int parent, int select)
{
    if(dp_cache[node][select] > -1)
        return dp_cache[node][select];

    int result = 0;
    for(int i = 0; i < tree[node].size(); i++)
        if(tree[node][i] != parent)
            if(select)
                result += dp(tree[node][i], node, 0);
            else
                result += max(dp(tree[node][i], node, 1), dp(tree[node][i], node, 0));
    return dp_cache[node][select] = result + (select ? w[node] : 0);
}

void dfs(int node, int parent, int prev)
{
    int flag = 0;
    if(!prev && (dp_cache[node][1] > dp_cache[node][0]))
    {
        v.push_back(node);
        flag = 1;
    }
    for(int i = 0; i < tree[node].size(); i++)
        if(tree[node][i] != parent)
            if(flag)
                dfs(tree[node][i], node, 1);
            else
                dfs(tree[node][i], node, 0);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 0; i < n - 1; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tree[tmp1].push_back(tmp2); tree[tmp2].push_back(tmp1);
    }

    memset(dp_cache, -1, sizeof(dp_cache));
    cout << max(dp(1, 0, 0), dp(1, 0, 1)) << '\n';
    dfs(1, 0, 0);
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';

    return 0;
}