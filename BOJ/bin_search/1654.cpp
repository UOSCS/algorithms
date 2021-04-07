#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int _count(int *arr, int K, int mid)
{
    int sum = 0;
    for(int i = 0; i < K; i++)
        sum += arr[i] / mid;
    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N, lower_limit, *arr, max = 0, left = 1;

    cin >> K >> N;
    arr = new int[K];
    for(ll i = 0; i < K; i++)
    {
        cin >> arr[i];
        if(max < arr[i])
            max = arr[i];
    }

    lower_limit = max / ((N + K - 1) / K);
    for(int right = lower_limit, mid, tmp; left < right; )
    {
        mid = ((ll)left + right + 1) / 2;
        tmp = _count(arr, K, mid);
        if(tmp < N)
            right = mid - 1;
        else
            left = mid;
    }
    cout << left << endl;

    delete[] arr;

    return 0;
}