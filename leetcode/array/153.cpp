class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left_most = nums[0], right_most = nums[nums.size() - 1];
        
        if (left_most < right_most)
            return nums[0];
        else {
            int low = 0, high = nums.size() - 1;
            
            while (low < high) {
                int mid = (low + high) >> 1;
                
                if (nums[mid] < right_most)
                    high = mid;
                else
                    low = mid + 1;
            }
            
            return nums[high];
        }
    }
};
