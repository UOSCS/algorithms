#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n, arr[2][100001], dp[2][100001] = {0};

        cin >> n;
        for(int j = 0; j < 2; j++)
            for(int k = 1; k <= n; k++)
                cin >> arr[j][k];
        
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        for(int j = 2; j <= n; j++)
        {
            dp[0][j] = arr[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
            dp[1][j] = arr[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }

    return 0;
}