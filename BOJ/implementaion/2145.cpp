#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    while(true)
    {
        int N;

        cin >> N;

        if(!N) break;

        while(true)
        {
            if(N < 10)
            {
                cout << N << '\n';
                
                break;
            }

            string N_str = to_string(N);

            int new_N = 0;

            for(int i = 0; i < N_str.length(); i++)
                new_N += N_str[i] - '0';

            N = new_N;
        }
    }

    return 0;
}