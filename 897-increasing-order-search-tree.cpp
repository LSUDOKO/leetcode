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
    vector<int>ans;
public:
    void helper(TreeNode* root){
        if(root==NULL){
            return ;
        }
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);

    }
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);
         TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;
        for(int x : ans) {
            curr->right = new TreeNode(x);
            curr = curr->right;
        }
        return dummy->right;
    }
};