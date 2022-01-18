#include <iostream>

#define BIAS 45

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int H, M;

    cin >> H >> M;

    if(M < BIAS)
    {
        if(--H < 0) H = 23;

        M += 60 - BIAS;
    }
    else
        M -= BIAS;

    cout << H << ' ' << M;

    return 0;
}