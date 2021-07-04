#include <iostream>

using namespace std;

int arr[100000], dp[100000][2];

int main(void)
{
    ios::sync_with_stdio(0);

    int N, ans;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    ans = dp[0][0] = arr[0];
    for(int i = 1; i < N; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    cout << ans;

    return 0;
}