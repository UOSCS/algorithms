#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int arr[10], sum = 0;

    for(int i = 0; i < 10; i++)
        cin >> arr[i];

    for(int i = 0; i < 10; i++)
    {
        if(abs(sum - 100) < abs(sum + arr[i] - 100)) break;
        else sum += arr[i];
    }

    cout << sum;

    return 0;
}