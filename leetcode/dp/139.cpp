class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = wordDict.size();
        map<string, bool> m;
        
        for (string word : wordDict)
            m[word] = true;
        
        int len_s = s.length();
        bool dp[301] = {false, };
        
        dp[0] = true;
        for (int i = 1; i <= len_s; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && m[s.substr(j, i - j)]) {
                    dp[i] = true;
                    
                    break;
                }
            }
        }
        
        return dp[len_s];
    }
};
