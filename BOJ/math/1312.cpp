#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int A, B, N;

    cin >> A >> B >> N;

    A %= B;

    if(!A) cout << 0;
    else
    {
        int answer;

        for(int i = 0; i < N; i++)
        {
            A *= 10;

            answer = A / B;

            A %= B;
        }

        cout << answer;
    }

    return 0;
}