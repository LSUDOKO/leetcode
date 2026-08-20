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
    bool isSame(TreeNode* root1,TreeNode* root2){
        if (root1==NULL and root2==NULL){
            return true;
        }
        if (root1==NULL or root2==NULL){
            return false;
        }
        return root1->val==root2->val and isSame(root1->left,root2->left) and isSame(root1->right,root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot==NULL){
            return true;
        }
        if (root==NULL){
            return false;
        }
        if (isSame(root,subRoot))return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};