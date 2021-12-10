#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string N;
    int B;

    cin >> N >> B;

    int mul = 1, answer = 0;

    for(int i = N.length() - 1; i >= 0; i--)
    {
        if(N[i] >= 'A' && N[i] <= 'Z')
            N[i] = N[i] - 'A' + 10 + '0';

        answer += mul * (N[i] - '0');

        mul *= B;
    }

    cout << answer;

    return 0;
}