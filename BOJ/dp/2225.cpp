#include <iostream>
#include <algorithm>

using namespace std;

long long dp_cache[201][201];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, divisor = 1000000000;

    cin >> N >> K;

    for(int i = 0; i <= N; i++)
        dp_cache[i][1] = 1;
    for(int i = 2; i <= K; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            for(int k = 0; k <= j; k++)
                dp_cache[j][i] += dp_cache[k][i - 1];
            dp_cache[j][i] %= divisor;
        }
    }

    cout << dp_cache[N][K] << '\n';

    return 0;
}