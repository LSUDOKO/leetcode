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
    TreeNode* prev=nullptr;
    void helper(TreeNode* root,int &mini){
        if (root==NULL){
            return ;
        }
        helper(root->left,mini);
        if (prev!=nullptr){
            mini=min(mini,abs(prev->val-root->val));
        }
        prev=root;
        helper(root->right,mini);
    }
public:
    
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        helper(root,mini);
        return mini;
    }
};