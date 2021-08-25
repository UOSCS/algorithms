#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, K, arr[100000], diff[100000];

    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];

        if(i)
            diff[i - 1] = arr[i] - arr[i - 1];
    }

    sort(diff, diff + N - 1, greater<>());

    int sum = 0;
    for(int i = 0; i < K - 1; i++)
        sum += diff[i];

    cout << arr[N - 1] - arr[0] - sum;

    return 0;
}