#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dp[4001][4001], max_len = 0;
    string s1, s2;

    cin >> s1 >> s2;

    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= s1.length(); i++)
        for(int j = 1; j <= s2.length(); j++)
            if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_len = max(dp[i][j], max_len);
            }

    cout << max_len;

    return 0;
}