#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    long long A, B;

    cin >> A >> B;

    long long sum = 0;

    if(A < B)
        sum = (B * (B + 1) >> 1) - (A * (A - 1) >> 1);
    else
        sum = (A * (A + 1) >> 1) - (B * (B - 1) >> 1);
        
    cout << sum << '\n';

    return 0;
}