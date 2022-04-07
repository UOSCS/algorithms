class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        bool answer = false;
        
        sort(nums.begin(), nums.end());
        
        int prev = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == prev) {
                answer = true;
                
                break;
            } else
                prev = nums[i];
        
        return answer;
    }
};
