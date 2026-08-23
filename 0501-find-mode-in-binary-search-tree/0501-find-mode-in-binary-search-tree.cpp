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
    TreeNode* prev=nullptr;
    int curr=0;
    int maxi=0;
    void inorder(TreeNode* root){
        if (root==NULL){
            return;
        }
        inorder(root->left);
        if (prev==nullptr || prev->val!=root->val){
            curr=1;
        }
        else{
            curr++;
        }
        if (curr>maxi){
            maxi=curr;
            ans.clear();
            ans.push_back(root->val);
        }
        else if (curr==maxi){
            ans.push_back(root->val);
        }
        prev=root;
        inorder(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};