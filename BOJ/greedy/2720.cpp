#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    int arr[4] = {25, 10, 5, 1};

    while(T--)
    {
        int C;

        cin >> C;

        int i = 0;

        while(i < 4)
        {
            int q = C / arr[i];

            if(C)
                cout << q << ' ';
            else
                cout << 0 << ' ';

            C %= arr[i++];
        }

        cout << '\n';
    }

    return 0;
}