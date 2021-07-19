#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    unsigned S, ans = 0;

    cin >> S;

    int i = 1;
    while(S >= i)
    {
        ans++;
        S -= i;
        i++;
    }

    cout << ans;

    return 0;
}