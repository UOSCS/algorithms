#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp(int n, int arr[], vector<int> v[], int dp_cache[])
{
    if(dp_cache[n] >= 0)
        return dp_cache[n];
    if(v[n].size())
        for(int i = 0; i < v[n].size(); i++)
            dp_cache[n] = max(dp_cache[n], dp(v[n][i], arr, v, dp_cache));
    else
        dp_cache[n]++;
    return dp_cache[n] += arr[n];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int arr[1001], dp_cache[1001];
        vector<int> v[1001];
        int N, K, W;

        cin >> N >> K;
        for(int i = 1; i <= N; i++)
            cin >> arr[i];
        for(int i = 0; i < K; i++)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            v[tmp2].push_back(tmp1);
        }
        cin >> W;

        memset(dp_cache, -1, sizeof(dp_cache));

        cout << dp(W, arr, v, dp_cache) << '\n';
    }

    return 0;
}