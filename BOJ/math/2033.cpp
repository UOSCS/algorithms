#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;
    
    for(int i = 10; i < 100000000; i *= 10)
    {
        if(N < i) break;

        double tmp = floor((double) N / i + 0.5);

        N = tmp * i;
    }

    cout << N;

    return 0;
}