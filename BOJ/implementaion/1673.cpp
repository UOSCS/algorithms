#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;

    while(cin >> N >> K)
    {
        int count = 0, remainder = 0;

        while(N)
        {
            count += N;

            remainder += N % K;

            N /= K;

            N += remainder / K;

            remainder %= K;
        }

        cout << count << '\n';
    }

    return 0;
}