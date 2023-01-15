class Solution {
public:
    void solve(int n, vector<int>& candidates, int target, vector<vector<int>>& answer, vector<int>& tmp) {

        int sum = accumulate(tmp.begin(), tmp.end(), 0);

        for (int i = n; i < candidates.size(); i++) {
            if (sum + candidates[i] < target) {
                tmp.push_back(candidates[i]);
                solve(i, candidates, target, answer, tmp);
                tmp.pop_back();
            } else if (sum + candidates[i] > target) {
                return;
            } else {
                tmp.push_back(candidates[i]);
                answer.push_back(tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> answer;
        vector<int> tmp;

        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, answer, tmp);

        return answer;
    }
};
