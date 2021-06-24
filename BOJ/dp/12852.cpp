#include <iostream>
#include <vector>

using namespace std;

int dp[1000001], trace[1000001];

int solve(int N)
{
    for(int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        trace[i] = i - 1;
        if(!(i % 3) && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            trace[i] = i / 3;
        }
        if(!(i % 2) && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            trace[i] = i / 2;
        }
    }

    return dp[N];
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    cout << solve(N) << '\n';
    while(N)
    {
        cout << N << ' ';
        N = trace[N];
    }

    return 0;
}