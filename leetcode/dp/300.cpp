class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    
        vector<int> answer;
        
        for (int num : nums) {
            int idx = lower_bound(answer.begin(), answer.end(), num) - answer.begin();
            
            if (idx == answer.size())
                answer.push_back(num);
            else
                answer[idx] = num;
        }
        
        return answer.size();
    }   
};
