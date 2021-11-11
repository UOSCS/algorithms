#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, K, arr[20];

    cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        char tmp;

        cin >> arr[i];

        if(i < N - 1)
            cin >> tmp;
    }

    while(K--)
    {
        for(int i = 0; i < N - 1; i++)
            arr[i] = arr[i + 1] - arr[i];

        N--;
    }

    for(int i = 0; i < N; i++)
    {
        cout << arr[i];

        if(i < N - 1)
            cout << ',';
    }

    return 0;
}