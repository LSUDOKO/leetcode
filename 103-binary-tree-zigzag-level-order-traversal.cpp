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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        q.push(root);
        int lvl=1;
        while(!q.empty()){
            int s=q.size();
            vector<int>ans;
            for (int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                ans.push_back(curr->val);
                if (curr->left)q.push(curr->left);
                if (curr->right)q.push(curr->right);
            }
            
            if (lvl%2==0){
                reverse(ans.begin(),ans.end());
                result.push_back(ans);
            }
            else{
                result.push_back(ans);
            }
            lvl++;
        }
        return result;
    }
};