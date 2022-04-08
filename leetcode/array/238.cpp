class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int nums_size = nums.size();
        vector<int> answer(nums_size);
        
        answer[nums_size - 1] = nums[nums_size - 1];
        for (int i = nums_size - 2; i > 0; i--)
            answer[i] = answer[i + 1] * nums[i];
        
        int prefix_product = 1;
        
        for (int i = 0; i < nums_size - 1; i++) {
            answer[i] = answer[i + 1] * prefix_product;
            prefix_product *= nums[i];
        }
        answer[nums_size - 1] = prefix_product;
        
        return answer;
    }
};
