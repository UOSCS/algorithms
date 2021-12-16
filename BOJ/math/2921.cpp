#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    int answer = 0;

    answer += (3 * N * (N + 1)) >> 1;

    for(int i = 2; i <= N; i++)
        answer += (3 * i * (i - 1)) >> 1;

    cout << answer;

    return 0;
}