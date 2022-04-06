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
    bool calc(TreeNode* root, int targetSum, int currentSum) {
        if (!root) return false;
        
        currentSum += root->val;
        if (!(root->left) && !(root->right)) {
            if (targetSum == currentSum) return true;
            else return false;
        }
        
        if (calc(root->left, targetSum, currentSum)) return true;
        
        return calc(root->right, targetSum, currentSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return calc(root, targetSum, 0);
    }
};
