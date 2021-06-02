#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int n, ans = 0;

    cin >> n;

    if(n < 5 && n & 1)
        ans = -1;
    else
        if((n % 5) & 1)
            ans = (n / 5) - 1 + ((n % 5) + 5) / 2;
        else
            ans = (n / 5) + ((n % 5) / 2);
    
    cout << ans;

    return 0;
}