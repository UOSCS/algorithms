#include <iostream>

using namespace std;

int dp[46];

int fibo(int n)
{
    if(dp[n])
        return dp[n];

    int ret;

    if(n < 2)
        ret = n;
    else
        ret = fibo(n - 1) + fibo(n - 2);

    return dp[n] = ret;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int n;

    cin >> n;

    cout << fibo(n);

    return 0;
}