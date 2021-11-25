#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T = 3, N = 8;

    while(T--)
    {
        int cur_len = 1, max_len = 1;
        char prev = '0';

        for(int i = 0; i < N; i++)
        {
            char c;

            cin >> c;

            if(prev != c)
                prev = c, cur_len = 1;
            else
                max_len = max(max_len, ++cur_len);
        }

        cout << max_len << '\n';
    }

    return 0;
}