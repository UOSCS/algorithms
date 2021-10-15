#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    for(int i = 0; i < 3; i++)
    {
        int N;

        cin >> N;

        long long answer = 0LL;

        int overflow = 0;

        for(int j = 0; j < N; j++)
        {
            long long n;
            
            cin >> n;

            if(answer > 0 && n > 0 && answer > LONG_LONG_MAX - n) overflow++;
            else if(answer < 0 && n < 0 && answer < LONG_LONG_MIN - n) overflow--;

            answer += n;
        }

        cout << ((overflow >= 0 ? (overflow == 0 ? (answer >= 0 ? (answer == 0 ? '0' : '+') : '-') : '+') : '-')) << '\n';
    }

    return 0;
}