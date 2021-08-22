#include <iostream>

using namespace std;

int N, dp[1001];

int calc(int n)
{
    if(n > N) return 0;
    if(dp[n]) return dp[n];
    if(n == N) return 1;

    return dp[n] += (calc(n + 1) + calc(n + 2)) % 10007;
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;

    calc(0);

    cout << dp[0];

    return 0;
}