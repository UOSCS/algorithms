#include <iostream>

using namespace std;

int N, arr[100000][3], max_dp[2][3], min_dp[2][3], d[3] = {-1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int total_max, total_min;

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];

    for(int i = 0; i < 3; i++)
        max_dp[0][i] = min_dp[0][i] = arr[0][i];
    for(int i = 1; i < N; i++)
    {
        max_dp[1][0] = arr[i][0] + max(max_dp[0][0], max_dp[0][1]);
        max_dp[1][1] = arr[i][1] + max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]);
        max_dp[1][2] = arr[i][2] + max(max_dp[0][1], max_dp[0][2]);

        min_dp[1][0] = arr[i][0] + min(min_dp[0][0], min_dp[0][1]);
        min_dp[1][1] = arr[i][1] + min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]);
        min_dp[1][2] = arr[i][2] + min(min_dp[0][1], min_dp[0][2]);

        for(int j = 0; j < 3; j++)
        {
            max_dp[0][j] = max_dp[1][j];
            min_dp[0][j] = min_dp[1][j];
        }
    }

    total_max = max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]);
    total_min = min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]);

    cout << total_max << ' ' << total_min << '\n';

    return 0;
}