#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, arr[1000], sum = 0;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    for(int i = 0; i < N; i++)
    {
        if(arr[i] > sum + 1)
            break;
        sum += arr[i];
    }

    cout << sum + 1 << '\n';

    return 0;
}