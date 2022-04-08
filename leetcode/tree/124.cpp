/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int answer = -30000000;
        
    int solve(TreeNode* root) {
        
        if (!root) return 0;
        
        int left_sum = solve(root->left);
        int right_sum = solve(root->right);
        
        int path_sum = max(root->val, root->val + max(left_sum, right_sum));
        
        answer = max(max(answer, path_sum), root->val + left_sum + right_sum);
        
        return path_sum;
    }
    
    int maxPathSum(TreeNode* root) {
        
        solve(root);
        
        return answer;
    }
};
