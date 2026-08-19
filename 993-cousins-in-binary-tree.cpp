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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            set<int>check;
            for (int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                check.insert(curr->val);
                if (curr->left && curr->right){
                    int left=curr->left->val;
                    int right=curr->right->val;
                    if ((x==right && y==left) || (x==left && y==right)){
                        return false;
                    }
                }
                if (curr->left)q.push(curr->left);
                if (curr->right)q.push(curr->right);
            }
            if (check.count(x) && check.count(y)){
                return true;
            }
        }
        return false;
    }
};