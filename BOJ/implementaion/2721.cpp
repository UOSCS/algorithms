#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    while(T--)
    {
        int n;

        cin >> n;

        int W_n = 0, pre_sum = 1;

        for(int i = 1; i <= n; i++)
        {
            pre_sum += i + 1;

            W_n += i * pre_sum;
        }

        cout << W_n << '\n';
    }

    return 0;
}