#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, arr[100001] = {0};

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    cin >> M;
    
    for(int i = 0; i < M; i++)
    {
        int low, high;
        cin >> low >> high;
        cout << arr[high] - arr[low - 1] << '\n';
    }

    return 0;
}