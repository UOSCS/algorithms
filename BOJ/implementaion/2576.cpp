#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T = 7;
    int min_odd = 100, sum_odd = 0;

    while(T--)
    {
        int N;

        cin >> N;

        if(N & 1)
        {
            min_odd = min(min_odd, N);

            sum_odd += N;
        }
    }

    if(min_odd == 100)
        cout << -1;
    else
        cout << sum_odd << '\n' << min_odd;

    return 0;
}