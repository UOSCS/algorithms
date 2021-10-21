#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, L, D;
    
    cin >> N >> L >> D;

    int time = D;

    while(true)
    {
        int tmp = time % (L + 5) - L;

        if((tmp >= 0 && tmp < 5) || time >= N * L + (N - 1) * 5) break;

        time += D;
    }

    cout << time;

    return 0;
}