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
    unordered_set<int>st;
public:
    bool helper(TreeNode* root,int k){
        if (root==NULL){
            return false;
        }
        int need=k-root->val;
        if(st.count(need)){
            return true;
        }
        st.insert(root->val);
        return helper(root->left,k)|| helper(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        return helper(root,k);
    }
};