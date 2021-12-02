#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int sum = 0, arr[101] = {0};

    for(int i = 0; i < 10; i++)
    {
        int n;

        cin >> n;

        sum += n;

        arr[n / 10]++;
    }

    int max_value = 0, mode;

    for(int i = 0; i < 101; i++)
        if(arr[i] > max_value)
            mode = i * 10, max_value = arr[i];

    cout << sum / 10 << '\n';

    cout << mode;

    return 0;
}