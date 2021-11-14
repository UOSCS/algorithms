#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int arr[5];

    for(int i = 0; i < 5; i++)
        cin >> arr[i];

    int sum = 0;

    for(int i = 0; i < 5; i++)
        sum += arr[i] * arr[i];

    cout << sum % 10;

    return 0;
}