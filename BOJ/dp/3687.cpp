#include <iostream>

using namespace std;

int num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
long long dp[101] = {0, 0, 1, 7, 4, 2, 6, 8, 10};

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    for(int i = 9; i <= 100; i++)
    {
        dp[i] = dp[i - 2] * 10 + num[2];
        for(int j = 3; j <= 7; j++)
            dp[i] = min(dp[i - j] * 10 + num[j], dp[i]);
    }

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cout << dp[n] << ' ';
        if(n & 1)
        {
            cout << 7;
            n -= 3;
        }
        for(int j = n >> 1; j > 0; j--)
            cout << 1;
        cout << '\n';
    }

    return 0;
}