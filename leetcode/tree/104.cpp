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
    int solve(TreeNode* root, int depth) {
        
        if (!root) return depth;
        
        return max(solve(root->left, depth + 1), solve(root->right, depth + 1));
    }
    
    int maxDepth(TreeNode* root) {
        
        return solve(root, 0);
    }
};
