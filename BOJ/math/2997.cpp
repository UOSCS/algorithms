#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int arr[3];

    cin >> arr[0] >> arr[1] >> arr[2];

    sort(arr, arr + 3);

    if(arr[1] - arr[0] == arr[2] - arr[1])
        cout << arr[2] + (arr[2] - arr[1]);
    else
        if(arr[1] - arr[0] < arr[2] - arr[1])
            cout << arr[1] + (arr[1] - arr[0]);
        else
            cout << arr[0] + (arr[2] - arr[1]);

    return 0;
}