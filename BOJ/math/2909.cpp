#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    double C;
    int K;

    cin >> C >> K;

    int mul = pow(10, K);

    C /= mul;

    C = round(C);

    C *= mul;

    cout << (int) C;

    return 0;
}