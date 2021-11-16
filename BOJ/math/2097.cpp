#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    long long N;

    cin >> N;

    long long root_N = sqrt(N);
    
    if(N < 4) cout << 4;
    else if(pow(root_N, 2) != N)
    {
        if(N - pow(root_N, 2) > root_N)
            cout << (root_N << 2);
        else
            cout << (((root_N - 1) + root_N) << 1);
    }
    else cout << ((root_N - 1) << 2);

    return 0;
}