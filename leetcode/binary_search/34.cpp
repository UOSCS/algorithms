class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lower_bound = -1, upper_bound = -1;
        int l, r;

        if (nums.empty()) {
            return {lower_bound, upper_bound};
        }

        l = 0; r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) >> 1;

            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (nums[l] == target) {
            lower_bound = l;
        } else {
            return {lower_bound, upper_bound};
        }

        r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r + 1) >> 1;

            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }

        upper_bound = l;

        return {lower_bound, upper_bound};
    }
};
