class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0, high = n - 1;
        int answer = -1;
        
        while (low <= high) {
            int mid = (low + high) >> 1;
            
            if (nums[mid] == target) {
                answer = mid;
                break;
            }
            
            if (nums[mid] >= nums[0]) {
                if (target < nums[mid] && target >= nums[0])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[n - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        
        return answer;
    }
};
