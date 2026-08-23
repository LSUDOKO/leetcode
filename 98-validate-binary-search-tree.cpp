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
    bool helper(TreeNode* root,long long low,long long high){
        if (root==NULL){
            return true;
        }
        if (root->val<=low || root->val>=high){
            return false;
        }
        return helper(root->left,low,root->val)&& helper(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
       return helper(root,LLONG_MIN,LLONG_MAX);
    }
};