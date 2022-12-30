class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> answer;
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            int req = target - nums[i];

            if (um.find(req) != um.end()) {
                answer.push_back(i);
                answer.push_back(um[req]);

                break;
            }

            um[nums[i]] = i;
        }

        return answer;
    }
};
