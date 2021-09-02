#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;

    cin >> N >> M;

    if(N == 1)
        cout << 1;
    else if(N == 2)
        cout << min(4, (M + 1) >> 1);
    else
        if(M < 7)
            cout << min(4, M);
        else
            cout << M - 2;

    return 0;
}