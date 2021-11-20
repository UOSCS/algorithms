#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    long long N;

    cin >> N;

    long long result = (3 * N * (N + 1) / 2 + N + 1) % 45678;

    cout << result;

    return 0;
}