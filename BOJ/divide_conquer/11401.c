#include <stdio.h>

#define DIVISOR 1000000007

typedef long long ll;

ll factorial(ll n, ll result)
{
    if(n == 0)
        return result;
    else
        return factorial(n - 1, (n * result) % DIVISOR);
}

ll _pow(ll n, ll expo)
{
    if(!expo)
        return 1;
    else
        if(!(expo % 2))
            return _pow((n * n) % DIVISOR, expo / 2);
        else
            return (n * _pow((n * n) % DIVISOR, (expo - 1) / 2)) % DIVISOR;
}

int main(void)
{
    ll N, K;
    ll tmp1, tmp2;

    scanf("%lld%lld", &N, &K);

    tmp1 = factorial(N, 1) % DIVISOR;
    tmp2 = _pow((factorial(K, 1) * factorial(N - K, 1)) % DIVISOR, DIVISOR - 2) % DIVISOR;
    printf("%lld\n", (tmp1 * tmp2) % DIVISOR);

    return 0;
}