#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll right;
    int N, K;

    cin >> N >> K;
    right = K;

    for(ll left = 1, mid; left < right; )
    {
        ll sum = 0;
        mid = (left + right) / 2;
        for(int i = 1; i <= N; i++)
            sum += min(mid / i, (ll)N);
        if(sum < K)
            left = mid + 1;
        else
            right = mid;
    }
    cout << right << endl;

    return 0;
}