#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    while(T--)
    {
        int even_min = 100, even_sum = 0;

        int i = 7;

        while(i--)
        {
            int n;

            cin >> n;

            if(!(n & 1))
            {
                even_min = min(even_min, n);

                even_sum += n;
            }
        }

        cout << even_sum << ' ' << even_min << '\n';
    }

    return 0;
}