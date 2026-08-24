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
    void helper(TreeNode* root,vector<TreeNode*>&ans){
        if (root==NULL){
            return ;
        }
        helper(root->left,ans);
        ans.push_back(root);
        helper(root->right,ans);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>ans;
        helper(root,ans);
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;
        for (int i=0;i<ans.size()-1;i++){
            if (ans[i]->val>ans[i+1]->val){
                if (first==nullptr){
                    first=ans[i];
                }
                second=ans[i+1];
            }
        }
        swap(first->val,second->val);
    }
};