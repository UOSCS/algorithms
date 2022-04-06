class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> num_idxs;
        
        for (int i = 0; i < nums.size(); i++)
            num_idxs.push_back({nums[i], i});    
        
        sort(num_idxs.begin(), num_idxs.end());
        sort(nums.begin(), nums.end());
        
        vector<int> answer;
        
        for (int i = 0; i < nums.size(); i++) {
            int other_num = target - nums[i];
            int j = lower_bound(nums.begin(), nums.end(), other_num) - nums.begin();
            
            if (j == nums.end() - nums.begin())
                continue;
            
            if (i == j)
                j++;
            
            if (nums[j] == other_num) {
                answer.push_back(num_idxs[i].second), answer.push_back(num_idxs[j].second);
                
                break;
            }
        }
        
        return answer;
    }
};
