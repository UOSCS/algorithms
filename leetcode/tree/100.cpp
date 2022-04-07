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
    vector<int> p_v, q_v;
    
    void pre_order(TreeNode* root, vector<int>& v) {
        
        if (!root) {
            
            v.push_back(NULL);
            
            return;
        }
        
        v.push_back(root->val);
        pre_order(root->left, v);
        pre_order(root->right, v);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        pre_order(p, p_v);
        pre_order(q, q_v);
        
        for (int i : p_v)
            cout << i << ' ';
        cout << '\n';
        for (int i : q_v)
            cout << i << ' ';
        
        return p_v == q_v ? true : false;
    }
};
