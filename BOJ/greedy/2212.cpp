#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, arr[10000], interval[9999], result;

    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    result = arr[N - 1] - arr[0];
    for(int i = 0; i < N - 1; i++)
        interval[i] = arr[i + 1] - arr[i];
    sort(interval, interval + N - 1, greater<int>());
    for(int i = 0; i < K - 1; i++)
        result -= interval[i];

    cout << result << '\n';

    return 0;
}