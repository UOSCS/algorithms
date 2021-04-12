#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int arr[500][2], dp_cache[500][500];

int dp(int left, int right)
{
    if(dp_cache[left][right])
        return dp_cache[left][right];
    
    if(left == right)
        dp_cache[left][right] = 0;
    else if(left + 1 == right)
        dp_cache[left][right] = arr[left][0] * arr[left][1] * arr[right][1];
    else
    {
        int min_value = INT_MAX;
        for(int mid = left, tmp; mid < right; mid++)
            min_value = min(min_value, dp(left, mid) + dp(mid + 1, right) + arr[left][0] * arr[mid][1] * arr[right][1]);
        dp_cache[left][right] = min_value;
    }
    return dp_cache[left][right];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i][0] >> arr[i][1];
    
    cout << dp(0, N - 1) << '\n';

    return 0;
}