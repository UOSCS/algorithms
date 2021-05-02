#include <iostream>
#include <cstring>

using namespace std;

int arr[501], dp_cache[501][501], sum[501];

int dp(int left, int right)
{
    if(dp_cache[left][right] != -1)
        return dp_cache[left][right];

    if(left == right)
        dp_cache[left][right] = 0;
    else if(left + 1 == right)
        dp_cache[left][right] = arr[left] + arr[right];
    else
    {
        int min = 2000000000;
        for(int i = left, tmp1, tmp2; i < right; i++)
        {
            tmp1 = dp(left, i); tmp2 = dp(i + 1, right);
            if(tmp1 + tmp2 < min)
                min = tmp1 + tmp2;
        }
        dp_cache[left][right] = min + sum[right] - sum[left - 1];
    }
    return dp_cache[left][right];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int K;
        cin >> K;
        for(int j = 1; j <= K; j++)
        {
            cin >> arr[j];
            sum[j] = sum[j - 1] + arr[j];
        }
        memset(dp_cache, -1, sizeof(dp_cache));
        cout << dp(1, K) << '\n';
    }

    return 0;
}