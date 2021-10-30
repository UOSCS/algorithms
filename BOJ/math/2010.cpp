#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, sum = 0;

    cin >> N;

    for(int i = 0, tmp; i < N; i++)
        cin >> tmp, sum += tmp;

    cout << sum - N + 1;

    return 0;
}