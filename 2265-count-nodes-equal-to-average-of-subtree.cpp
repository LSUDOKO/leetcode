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
    int result;
public:
    pair<int,int>solve(TreeNode* root){
        if (root==NULL){
            return {0,0};
        }
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        int leftsum=left.first;
        int leftcount=left.second;
        int rightsum=right.first;
        int rightcount=right.second;
        int sum=leftsum+rightsum+root->val;
        int count=leftcount+rightcount+1;
        int avg=sum/count;
        if (avg==root->val){
            result++;
        }
        return {sum,count};

        
    }
    int averageOfSubtree(TreeNode* root) {
        result=0;
        solve(root);
        return result;
    }
};