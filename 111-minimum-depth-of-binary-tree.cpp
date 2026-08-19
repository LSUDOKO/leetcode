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
    int minDepth(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        if (root==NULL){
            return 0;
        }
        int lvl=1;
        while(!q.empty()){
            int s=q.size();
            for (int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                if (curr->left==NULL && curr->right==NULL){
                    return lvl;
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            lvl++;
        }
        return lvl;
    }
};