#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int arr[5], sum = 0;

    for(int i = 0; i < 5; i++)
        cin >> arr[i], sum += arr[i];

    sort(arr, arr + 5);

    int average = sum / 5;
    int c_value = arr[2];

    cout << average << '\n' << c_value;

    return 0;
}