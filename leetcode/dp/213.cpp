class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        int dp1[101] = {0, nums[0], };
        int dp2[101] = {0, };
        
        if (n == 1)
            return nums[0];
        
        for (int i = 2; i < n; i++)
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
        
        for (int i = 2; i <= n; i++)
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
        
        return max(dp1[n - 1], dp2[n]);
    }
};
