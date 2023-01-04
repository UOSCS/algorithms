class Solution {
public:

    string longestPalindrome(string s) {

        bool dp[1000][1000] = {false, };
        int start_idx = 0, max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length() - i; j++) {
                if (!i || (i == 1 && s[j] == s[j + i])) {
                    dp[j][j + i] = true;
                } else {
                    dp[j][j + i] = (s[j] == s[j + i]) && (dp[j + 1][j + i - 1]);
                }

                if (dp[j][j + i] && max_len < i + 1) {
                    start_idx = j;
                    max_len = i + 1;
                }
            }
        }

        return s.substr(start_idx, max_len);
    }
};
