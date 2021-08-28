#include <iostream>

using namespace std;

int N;
long dp[2][91];

long calc(int current, int depth)
{
    if(depth >= N)
        return 1;
    if(dp[current][depth])
        return dp[current][depth];

    if(current)
        dp[current][depth] += calc(0, depth + 1);
    else
        dp[current][depth] += calc(1, depth + 1) + calc(0, depth + 1);

    return dp[current][depth];
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;

    cout << calc(1, 1);

    return 0;
}