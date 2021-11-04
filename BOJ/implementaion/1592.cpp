#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M, L;
    int arr[51] = {0};

    cin >> N >> M >> L;

    int idx = 1, count = 0;

    arr[idx] = 1;

    while(true)
    {
        if(arr[idx] >= M) break;

        if(arr[idx] & 1) idx += L;
        else idx -= L;

        if(idx > N) idx -= N;
        else if(idx < 1) idx += N;

        arr[idx]++;

        count++;
    }

    cout << count;

    return 0;
}