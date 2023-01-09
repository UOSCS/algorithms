class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (target < sum) {
                    right--;
                } else if (target > sum) {
                    left++;
                } else {
                    answer.push_back({nums[i], nums[left], nums[right]});

                    while (left + 1 < nums.size() && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while (right - 1 > i && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return answer;
    }
};

// -4 -1 -1 0 1 2
