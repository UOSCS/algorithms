#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    while(T--)
    {
        int a, b;

        cin >> a >> b;

        int a_b_gcd = gcd(a, b);

        cout << (a * b / a_b_gcd) << ' ';

        cout << a_b_gcd << '\n';
    }

    return 0;
}