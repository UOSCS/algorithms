#include <iostream>
#include <algorithm>

using namespace std;

long long N, arr[6];

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < 6; i++)
        cin >> arr[i];

    long long sum = 0;

    if(N == 1)
    {
        sort(arr, arr + 6);
        for(int i = 0; i < 5; i++)
            sum += arr[i];
    }
    else
    {
        arr[0] = min(arr[0], arr[5]);
        arr[1] = min(arr[1], arr[4]);
        arr[2] = min(arr[2], arr[3]);

        long long vertex = arr[0] + arr[1] + arr[2];
        long long edge = min(min(arr[0] + arr[1], arr[1] + arr[2]), arr[0] + arr[2]);
        long long inner = min(min(arr[0], arr[1]), arr[2]);

        sum = (vertex << 2) + ((edge << 2) * ((N << 1) - 3)) + 
              (inner * ((N - 2) * (N - 2) + 
              (((N - 2) * (N - 1)) << 2)));
    }

    cout << sum;

    return 0;
}