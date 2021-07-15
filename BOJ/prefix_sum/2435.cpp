#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, K, arr[101] = {0}, ans = -10000;

    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for(int i = 0; i <= N - K; i++)
        ans = max(ans, arr[i + K] - arr[i]);
    
    cout << ans;

    return 0;
}