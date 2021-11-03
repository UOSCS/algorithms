#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, arr[50];

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int left = 0, current_height = 0;

    for(int i = 0; i < N; i++)
        if(arr[i] > current_height)
            current_height = arr[i], left++;

    int right = 0;

    current_height = 0;

    for(int i = N - 1; i >= 0; i--)
        if(arr[i] > current_height)
            current_height = arr[i], right++;

    cout << left << '\n' << right;

    return 0;
}