#include <iostream>
#include <cmath>

using namespace std;

int calc(int a, int b)
{
    if(!b)
        return 1;

    if(b & 1)
        return (calc(a * a % 10, b >> 1) * a) % 10;
    else
        return calc(a * a % 10, b >> 1) % 10;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        int a, b;

        cin >> a >> b;

        int result = calc(a, b);

        if(result)
            cout << result;
        else
            cout << 10;
        cout << '\n';
    }

    return 0;
}