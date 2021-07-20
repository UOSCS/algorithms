#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, L, arr[1000], ans = 0;
    double current;

    cin >> N >> L;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    current = arr[0] - 0.5;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] < current)
            continue;
        current = arr[i] - 0.5 + L;
        ans++;
    }

    cout << ans;

    return 0;
}