#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, K;

    cin >> N >> K;

    int count = 0, answer = 0;

    for(int i = 1; i <= N; i++)
    {
        if(!(N % i)) count++;

        if(count >= K)
        {
            answer = i;

            break;
        }
    }

    cout << answer;

    return 0;
}