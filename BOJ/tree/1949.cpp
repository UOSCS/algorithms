#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int population[10001], dp_cache[10001][2];
vector<int> tree[10001];

int dp(int node, int parent, int now)
{
    if(dp_cache[node][now] > -1)
        return dp_cache[node][now];

    int result = 0;
    for(int i = 0; i < tree[node].size(); i++)
        if(tree[node][i] != parent)
        {
            if(now)
                result += dp(tree[node][i], node, 0);
            else
                result += max(dp(tree[node][i], node, 0), dp(tree[node][i], node, 1));
        }
    return dp_cache[node][now] = result + (now ? population[node] : 0);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> population[i];
    for(int i = 0; i < N - 1; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tree[tmp1].push_back(tmp2); tree[tmp2].push_back(tmp1);
    }

    memset(dp_cache, -1, sizeof(dp_cache));
    cout << max(dp(1, 0, 0), dp(1, 0, 1)) << '\n';

    return 0;
}