#include <iostream>
#include <map>

using namespace std;

map<long long, long long> m;
long long N, P, Q;

long long dp(long long n)
{
    if(m[n])
        return m[n];
    return m[n] = dp(n / P) + dp(n / Q);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> Q;

    m[0] = 1;

    cout << dp(N);

    return 0;
}