#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int M, N, sum = 0, min_num = 10000;

    cin >> M >> N;

    for(int i = M; i <= N; i++)
        if(pow((int) sqrt(i), 2) == i)
            sum += i, min_num = min(min_num, i);

    if(min_num != 10000)
        cout << sum << '\n' << min_num;
    else
        cout << -1;

    return 0;
}