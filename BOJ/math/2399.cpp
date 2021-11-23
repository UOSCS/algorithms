#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int n, arr[10000];

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    long long sum = 0LL;

    for(int i = 0; i < n; i++)
        sum += (long long) arr[i] * ((i << 1) - n + 1);

    cout << (sum << 1);

    return 0;
}