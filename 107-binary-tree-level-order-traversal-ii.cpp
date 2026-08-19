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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        if (root==NULL){
            return ans;
        }
        while(!q.empty()){
            int s=q.size();
            vector<int>result;
            for (int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                result.push_back(curr->val);
                if (curr->left)q.push(curr->left);
                if (curr->right)q.push(curr->right);
            }
            ans.push_back(result);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};