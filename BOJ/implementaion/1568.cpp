#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    int time = 0, K = 1;

    while(N)
    {
        if(N < K)
            K = 1;

        N -= K, time++, K++;
    }

    cout << time;

    return 0;
}