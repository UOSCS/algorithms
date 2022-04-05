class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {0, };
        
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int left = 0, right = i - 1;
            
            while (left < right)
                dp[i] += (dp[left++] * dp[right--]) << 1;
            
            if (left == right)
                dp[i] += dp[left] * dp[right];
        }
        
        return dp[n];
    }
};
