#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, Q, n[100], q[1000], arr[10000];

    cin >> N >> Q;
    for(int i = 0; i < N; i++)
        cin >> n[i];
    for(int i = 0; i < Q; i++)
        cin >> q[i];

    int i = 0, idx = 0;
    while(i < N)
    {
        for(int j = 0; j < n[i]; j++)
            arr[idx + j] = i;

        idx += n[i++];
    }

    for(int i = 0; i < Q; i++)
        cout << arr[q[i]] + 1 << '\n';

    return 0;
}