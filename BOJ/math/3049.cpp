#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    cout << N * (N - 1) * (N - 2) * (N - 3) / 24;

    return 0;
}