#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, arr[1000];

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int start = arr[0], end = arr[0], max_h = 0;

    for(int i = 1; i < N; i++)
    {
        if(end < arr[i])
            end = arr[i];
        else
        {
            max_h = max(max_h, end - start);

            start = end = arr[i];
        }
    }

    max_h = max(max_h, end - start);

    cout << max_h;

    return 0;
}