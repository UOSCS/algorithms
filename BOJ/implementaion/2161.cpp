#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, arr[2000];

    cin >> N;

    for(int i = 0; i < N; i++)
        arr[i] = i + 1;

    int idx = 0, end = N - 1;

    while(idx < end)
    {
        cout << arr[idx++] << ' ';

        arr[++end] = arr[idx++];
    }

    cout << arr[idx];

    return 0;
}