#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll get_total(int *arr, int N, int height)
{
    ll sum = 0;
    for(int i = 0; i < N; i++)
        if(arr[i] > height)
            sum += arr[i] - height;
    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, *arr, max = 0, left = 0;

    cin >> N >> M;
    arr = new int[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if(max < arr[i])
            max = arr[i];
    }

    for(int right = max, mid; left < right; )
    {
        ll tmp;
        mid = (left + right + 1) / 2;
        tmp = get_total(arr, N, mid);
        if(tmp < M)
            right = mid - 1;
        else
            left = mid;
    }
    cout << left << endl;

    return 0;
}