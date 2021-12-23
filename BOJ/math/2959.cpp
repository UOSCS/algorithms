#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int arr[4];

    for(int i = 0; i < 4; i++)
        cin >> arr[i];

    sort(arr, arr + 4);

    cout << arr[0] * arr[2];

    return 0;
}