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
    TreeNode* solve(vector<int>&nums,int &index,int bound){
       if (index==nums.size()||nums[index]>bound){
            return nullptr;
       }
       TreeNode* root=new TreeNode(nums[index++]);
       root->left=solve(nums,index,root->val);
       root->right=solve(nums,index,bound);
       return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return solve(preorder,index,INT_MAX);
    }
};