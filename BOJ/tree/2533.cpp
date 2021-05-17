#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> tree[1000001];
int dp_cache[1000001][2];

int dp(int node, int ea, int parent)
{
    int &dc = dp_cache[node][ea];
    if(dc != -1)
        return dc;

    dc = 0;
    for(int i = 0; i < tree[node].size(); i++)
        if(tree[node][i] != parent)
            if(ea)
                dc += min(dp(tree[node][i], 1, node), dp(tree[node][i], 0, node));
            else
                dc += dp(tree[node][i], 1, node);
    return dc += ea;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tree[tmp1].push_back(tmp2); tree[tmp2].push_back(tmp1);
    }

    memset(dp_cache, -1, sizeof(dp_cache));

    cout << min(dp(1, 1, 0), dp(1, 0, 0)) << '\n';

    return 0;
}