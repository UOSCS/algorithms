#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;

    while(T--)
    {
        int n;

        cin >> n;

        int n_max = 1;

        while(n != 1)
        {
            n_max = max(n_max, n);

            if(n & 1)
                n = n * 3 + 1;
            else
                n >>= 1;
        }

        cout << n_max << '\n';
    }

    return 0;
}