#include <iostream>
#include <algorithm>

using namespace std;

bool is_possible(int *arr, int N, int distance, int C)
{
    int count = 1;
    for(int i = 1, prev = arr[0]; i < N; i++)
        if(arr[i] - prev >= distance)
        {
            count++;
            prev = arr[i];
        }
    return count >= C;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, C, *arr, low = 1;

    cin >> N >> C;
    arr = new int[N];
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    for(int high = arr[N - 1] - arr[0], mid, flag; low < high; )
    {
        mid = (low + high + 1) / 2;
        flag = is_possible(arr, N, mid, C);
        if(flag)
            low = mid;
        else
            high = mid - 1;
    }
    cout << low << endl;

    return 0;
}