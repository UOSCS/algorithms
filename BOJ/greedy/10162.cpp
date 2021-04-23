#include <iostream>

using namespace std;

int main(void)
{
    int T, arr[] = {300, 60, 10};

    cin >> T;

    if(T % 10)
        cout << "-1\n";
    else
    {
        for(int i = 0, count; i < 3; i++)
        {
            count = T / arr[i];
            T %= arr[i];
            cout << count << ' ';
        }
    }

    return 0;
}