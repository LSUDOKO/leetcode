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
    int left(TreeNode* root){
        int h=0;
        while(root!=NULL){
            h++;
            root=root->left;
        }
        return h;
    }
    int right(TreeNode* root){
        int h=0;
        while(root!=NULL){
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if (root==NULL){
            return 0;
        }
        if (left(root)==right(root)){
            return (1<<left(root))-1;
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }   
};