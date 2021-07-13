#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N, arr[1001] = {0}, ans = -1000000;

        cin >> N;
        for(int j = 1; j <= N; j++)
        {
            cin >> arr[j];
            arr[j] += arr[j - 1];
        }

        for(int j = 0; j < N; j++)
            for(int k = j + 1; k <= N; k++)
                ans = max(ans, arr[k] - arr[j]);
            

        cout << ans << '\n';
    }

    return 0;
}