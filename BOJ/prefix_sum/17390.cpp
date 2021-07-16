#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q, arr[300001] = {0};

    cin >> N >> Q;

    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    
    sort(arr + 1, arr + N + 1);

    for(int i = 1; i <= N; i++)
        arr[i] += arr[i - 1];

    for(int i = 0; i < Q; i++)
    {
        int L, R;

        cin >> L >> R;
        
        cout << arr[R] - arr[L - 1] << '\n';
    }

    return 0;
}