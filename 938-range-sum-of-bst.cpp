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
    int total=0;
    void inorder(TreeNode* root,int low,int high){
        if (root==NULL){
            return ;
        }
        inorder(root->left,low,high);
        if (root->val>=low && root->val<=high){
            total+=root->val;
        }
        if (root->val>high){
            return ;
        }
        inorder(root->right,low,high);
    }
public:

    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root,low,high);
        return total;
    }
};