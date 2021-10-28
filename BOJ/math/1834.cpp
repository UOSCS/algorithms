#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    long long N, answer = 0LL;

    cin >> N;

    long long tmp = N;

    while(--tmp)
        answer += N * tmp + tmp;

    cout << answer;

    return 0;
}