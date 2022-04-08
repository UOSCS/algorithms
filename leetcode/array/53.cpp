class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int dp[100000];
        int n = nums.size();
        int answer = nums[0];
        
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
            answer = max(answer, dp[i] = max(nums[i], dp[i - 1] + nums[i]));   
        
        return answer;
    }
};
