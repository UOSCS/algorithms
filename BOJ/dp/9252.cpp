#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1, s2, LCS[1001][1001];

    cin >> s1 >> s2;

    for(int i = 1; i <= s1.length(); i++)
        for(int j = 1; j <= s2.length(); j++)
            if(s1[i - 1] == s2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + s1[i - 1];
            else
                LCS[i][j] = LCS[i - 1][j].length() > LCS[i][j - 1].length() ? LCS[i - 1][j] : LCS[i][j - 1];

    cout << LCS[s1.length()][s2.length()].length() << '\n';
    cout << LCS[s1.length()][s2.length()] << '\n';

    return 0;
}