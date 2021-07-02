#include <iostream>
#include <cstring>

using namespace std;

int dp[500][500];
string s;

int calc(int l, int r)
{
    if(dp[l][r] != -1)
        return dp[l][r];
    if(l >= r)
        return dp[l][r] = 0;
    
    if((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c'))
        dp[l][r] = calc(l + 1, r - 1) + 2;
    int tmp = -1;
    for(int i = l; i < r; i++)
        tmp = max(tmp, calc(l, i) + calc(i + 1, r));
    dp[l][r] = max(dp[l][r], tmp);
    
    return dp[l][r];
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> s;

    memset(dp, -1, sizeof(dp));
    cout << calc(0, s.length() - 1);

    return 0;
}