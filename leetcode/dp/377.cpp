class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        unsigned long long dp[1001] = {1, };
        
        for (int i = 1; i <= target; i++)
            for (int val : nums)
                if (val <= i)
                    dp[i] += dp[i - val];
        
        return (int) dp[target];
    }
};
