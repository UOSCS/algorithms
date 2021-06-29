#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string s1, s2, s3;
    int s1_len, s2_len, s3_len, dp[101][101][101] = {0};

    cin >> s1 >> s2 >> s3;

    s1_len = s1.length(), s2_len = s2.length(), s3_len = s3.length();
    for(int i = 1; i <= s1_len; i++)
        for(int j = 1; j <= s2_len; j++)
            for(int k = 1; k <= s3_len; k++)
                if(s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));

    cout << dp[s1_len][s2_len][s3_len];

    return 0;
}