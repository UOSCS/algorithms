class Solution {
public:
    void solve(vector<string>& answer, int left, int right, string s) {

        if (!left && !right) {
            answer.push_back(s);
        }
        
        if (left > 0) {
            solve(answer, left - 1, right, s + "(");
        }
        
        if (left < right) {
            solve(answer, left, right - 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> answer;

        solve(answer, n, n, "");

        return answer;
    }
};
